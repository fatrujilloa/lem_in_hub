/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:46:40 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/11 17:02:01 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	uc;
	size_t			i;
	void			*loc;

	str = (unsigned char*)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == uc)
		{
			loc = (void*)str;
			return (loc);
		}
		else
		{
			i++;
			str++;
		}
	}
	return (NULL);
}
