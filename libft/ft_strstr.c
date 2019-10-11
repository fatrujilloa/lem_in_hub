/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 22:34:18 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/11 14:58:45 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (!*haystack && !n_len)
		return ((char*)haystack);
	while (*haystack)
	{
		if (ft_strncmp(haystack, needle, n_len) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
