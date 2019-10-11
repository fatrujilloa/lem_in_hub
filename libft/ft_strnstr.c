/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 22:34:18 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/26 15:02:13 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** If needle is NULL it crashes.
** If needle = "" it returns haystack.
** If strlen(needle) > 0 and len = 0 returns NULL.
** If strlen(needle) > 0, len > 0 and haystack = NULL it crashes.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	i;

	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char*)haystack);
	if (!len)
		return (NULL);
	if (*haystack)
		if (len < n_len - 1)
			return (NULL);
	i = 0;
	while (i < len - n_len + 1 && *haystack)
	{
		if (ft_strncmp(haystack, needle, n_len) == 0)
			return ((char*)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
