/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 21:57:52 by ftrujill          #+#    #+#             */
/*   Updated: 2018/12/26 22:27:02 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the position of the last occurence of c in the string s.
** If c does not occur in the string it returns the -1.
** If s = NULL it returns -1.
*/

ssize_t	ft_index_rev(char c, char *s)
{
	ssize_t	i;

	if (!s)
		return (-1);
	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] == c)
			return (i);
		i--;
	}
	return (i);
}
