/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 22:19:36 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/10 22:31:17 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	cc;

	i = ft_strlen(s) + 1;
	s = s + i - 1;
	cc = c;
	while (i != 0)
	{
		if (*s == cc)
		{
			str = (char*)s;
			return (str);
		}
		else
		{
			i--;
			s--;
		}
	}
	return (NULL);
}
