/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin_allocf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:56:02 by ftrujill          #+#    #+#             */
/*   Updated: 2018/12/19 14:04:04 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates enough space to join the memory zones of sizes n1 and n2 pointed
** to by s1 and s2 respectively. It then frees the passed pointers.
*/

void	*ft_memjoin_allocf(void *s1, void *s2, size_t n1, size_t n2)
{
	void	*ptr;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
	{
		if (!(ptr = !s1 ? ft_realloc(s2, n2) : ft_realloc(s1, n1)))
			return (NULL);
		free(!s1 ? s1 : s2);
		return (ptr);
	}
	if (!(ptr = malloc(n1 + n2)))
		return (NULL);
	ft_memmove(ptr, s1, n1);
	ft_memmove((char*)ptr + n1, s2, n2);
	free(s1);
	free(s2);
	return (ptr);
}
