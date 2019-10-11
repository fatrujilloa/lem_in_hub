/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:39:14 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/24 18:45:11 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_sizetab(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		i = *s ? i + 1 : i;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	**tab;

	if (!s)
		return (NULL);
	size = ft_sizetab(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*s == c)
			s++;
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		if (!(tab[i] = ft_strsub(s, 0, j)))
			return (NULL);
		i++;
		s = s + j;
	}
	tab[i] = 0;
	return (tab);
}
