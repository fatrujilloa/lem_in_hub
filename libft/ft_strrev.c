/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 11:22:20 by ftrujill          #+#    #+#             */
/*   Updated: 2018/12/27 11:22:29 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	size_t	len;
	size_t	i;
	char	c;

	if (!str)
		return ;
	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		c = str[len - 1 - i];
		str[len - 1 - i] = str[i];
		str[i++] = c;
	}
}
