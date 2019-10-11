/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:54:43 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/10 21:08:03 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	l1;
	size_t	l2;
	size_t	i;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	i = 0;
	if (ft_memnlap_fwd(s1, s2, l1 + l2))
		return (s1);
	while (i < l2)
	{
		s1[l1 + i] = s2[i];
		i++;
	}
	s1[l1 + l2] = 0;
	return (s1);
}
