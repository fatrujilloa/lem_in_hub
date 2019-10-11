/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:41:06 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/17 18:57:05 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*cpy;
	size_t	i;

	if (!s || !(cpy = ft_strdup(s)))
		return (NULL);
	i = 0;
	while (cpy && *cpy)
	{
		*cpy = f(i++, *cpy);
		cpy++;
	}
	return (cpy - ft_strlen(s));
}
