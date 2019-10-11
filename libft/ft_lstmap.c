/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:27:08 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/26 14:01:43 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*elem;
	t_list	*next;

	if (!f || !lst)
		return (lst);
	if (!(newlst = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	elem = newlst;
	lst = lst->next;
	while (lst)
	{
		if (!(next = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		elem->next = next;
		elem = next;
		lst = lst->next;
	}
	return (newlst);
}
