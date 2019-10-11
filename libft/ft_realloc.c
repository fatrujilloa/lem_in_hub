/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 22:51:53 by ftrujill          #+#    #+#             */
/*   Updated: 2018/12/19 14:04:45 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Reallocates the memory zone (of the given size) pointed to by ptr.
*/

void	*ft_realloc(void *ptr, size_t size)
{
	void	*newptr;

	if (!(newptr = malloc(size)))
		return (NULL);
	ft_memcpy(newptr, ptr, size);
	return (newptr);
}
