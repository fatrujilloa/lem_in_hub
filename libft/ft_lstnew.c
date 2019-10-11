/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:38:28 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/18 17:53:11 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		new->content = NULL;
	else
	{
		if (!(new->content = malloc(content_size)))
			return (NULL);
		ft_memmove(new->content, content, content_size);
	}
	new->content_size = content ? content_size : 0;
	new->next = NULL;
	return (new);
}
