/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memoverlap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 19:09:36 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/10 19:32:54 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_memlap_fwd(void *s1, void *s2)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char*)s1;
	str2 = (char*)s2;
	i = 0;
	while (i < ft_strlen(str1))
	{
		if (str1 + i == str2)
			return (i);
		else
			i++;
	}
	return (0);
}
