/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:41:06 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/17 18:54:31 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*cpy;

	if (!s || !(cpy = ft_strdup(s)))
		return (NULL);
	while (cpy && *cpy)
	{
		*cpy = f(*cpy);
		cpy++;
	}
	return (cpy - ft_strlen(s));
}
