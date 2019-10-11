/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:52:44 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/10 21:54:38 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (ft_memnlap_fwd(dst, src, ft_strlen(src)))
		return (dst);
	while (i <= ft_strlen(src))
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
