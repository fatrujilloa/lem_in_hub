/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 21:57:52 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/10 22:26:44 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	l;
	char	*str;
	char	cc;

	i = 0;
	cc = c;
	l = ft_strlen(s);
	while (i <= l)
	{
		if (*s == cc)
		{
			str = (char*)s;
			return (str);
		}
		else
		{
			i++;
			s++;
		}
	}
	return (NULL);
}
