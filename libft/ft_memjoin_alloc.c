/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin_alloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:56:02 by ftrujill          #+#    #+#             */
/*   Updated: 2018/12/19 14:02:16 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates enough space to join the memory zones of sizes n1 and n2 pointed
** to by s1 and s2 respectively.
*/

void	*ft_memjoin_alloc(void *s1, void *s2, size_t n1, size_t n2)
{
	void	*ptr;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
	{
		if (!(ptr = !s1 ? ft_realloc(s2, n2) : ft_realloc(s1, n1)))
			return (NULL);
		return (ptr);
	}
	if (!(ptr = malloc(n1 + n2)))
		return (NULL);
	ft_memcpy(ptr, s1, n1);
	ft_memcpy(ptr + n1, s2, n2);
	return (ptr);
}
