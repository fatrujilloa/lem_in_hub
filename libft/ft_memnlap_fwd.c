/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnlap_fwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 19:33:21 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/10 20:30:25 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_memnlap_fwd(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char*)s1;
	str2 = (char*)s2;
	i = 0;
	while (i <= n)
	{
		if (str1 + i == str2)
			return (i);
		else
			i++;
	}
	return (0);
}
