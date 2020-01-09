/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:04:51 by khakala           #+#    #+#             */
/*   Updated: 2019/10/29 17:14:33 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int				count_words(const char *str, char c)
{
	int count;
	int z;

	z = 0;
	count = 0;
	while (str[z])
	{
		while (str[z] == c)
			z++;
		if (str[z] != c && str[z] != '\0')
			count++;
		while (str[z] != c && str[z] != '\0')
			z++;
	}
	return (count);
}

static int		word_length(char const *str, char c)
{
	int	x;
	int	len;

	x = 0;
	len = 0;
	while (str[x] == c)
		x++;
	while (str[x] != c && str[x] != '\0')
	{
		x++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		x;
	int		j;
	int		k;
	char	**str2;

	if (!s || !(str2 = (char **)malloc(sizeof(*str2) *
		(count_words(s, c) + 1))))
		return (NULL);
	x = -1;
	j = 0;
	while (++x < count_words(s, c))
	{
		k = 0;
		if (!(str2[x] = ft_strnew(word_length(&s[j], c) + 1)))
			str2[x] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str2[x][k++] = s[j++];
		str2[x][k] = '\0';
	}
	str2[x] = NULL;
	return (str2);
}
