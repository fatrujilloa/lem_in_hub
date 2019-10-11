/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:36:12 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/24 18:49:34 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_stop(unsigned char c, unsigned char *s, size_t n)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (i < n)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			overlap;
	size_t			stop;
	unsigned char	uc;
	unsigned char	*cdst;
	unsigned char	*csrc;

	if (n == 0)
		return (NULL);
	uc = (unsigned char)c;
	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	stop = ft_stop(uc, csrc, n);
	overlap = stop < n ? stop : n - 1;
	if (ft_memnlap_fwd(dst, src, overlap)
						|| ft_memnlap_fwd(src, dst, overlap))
		return (NULL);
	ft_memcpy(dst, src, overlap + 1);
	return (stop < n ? (void*)(cdst + overlap + 1) : NULL);
}
