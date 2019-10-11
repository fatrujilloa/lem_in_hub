/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 21:57:52 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/18 20:53:57 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the position of the first occurence of c in the string s.
** If c does not occur in the string it returns the lenght of the string + 1.
** If s = NULL it returns 0.
*/

size_t	ft_index_uc(unsigned char c, unsigned char *s)
{
	size_t	i;
	size_t	l;

	if (!s)
		return (0);
	l = ft_strlen((char*)s);
	i = 0;
	while (i <= l)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}
