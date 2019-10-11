/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:27:31 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/17 16:55:35 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*trunc;
	size_t	i;

	if ((!s && len) || !(trunc = (char*)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		trunc[i] = s[start + i];
		i++;
	}
	trunc[len] = 0;
	return (trunc);
}
