/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 21:57:52 by ftrujill          #+#    #+#             */
/*   Updated: 2018/12/19 14:00:50 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurence of c in the memory location pointed to by s where
** no more than n bytes are searched.
** If c is not found the function returns n.
** If s = NULL it returns 0.
*/

size_t	ft_memindex(unsigned char c, void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	if (!s)
		return (0);
	i = 0;
	str = (unsigned char*)s;
	while (i < n)
	{
		if (*str++ == c)
			return (i);
		i++;
	}
	return (i);
}
