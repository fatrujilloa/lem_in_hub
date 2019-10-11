/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:46:10 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/18 19:14:07 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;

	if (len == 0 || !ft_memnlap_fwd(src, dst, len - 1))
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len)
		{
			cdst = (char*)dst;
			csrc = (char*)src;
			cdst[len - 1] = csrc[len - 1];
			len--;
		}
	}
	return (dst);
}
