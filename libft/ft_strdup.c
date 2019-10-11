/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:38:33 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/18 13:49:48 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;

	if (!(copy = (char*)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	i = 0;
	while (i <= ft_strlen(s1))
	{
		copy[i] = s1[i];
		i++;
	}
	return (copy);
}
