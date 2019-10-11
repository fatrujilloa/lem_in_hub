/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:59:15 by ftrujill          #+#    #+#             */
/*   Updated: 2018/12/19 14:00:10 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Deletes and frees the link pointed to by prev->next.
** If prev = NULL the first element of the list is deleted.
** If prev->next = NULL or *lst = NULL nothing is done.
*/

void	ft_lstdelnext(t_list **lst, t_list **prev)
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	if (!(*prev))
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->content);
		free(tmp);
		return ;
	}
	if ((tmp = (*prev)->next) == NULL)
		return ;
	(*prev)->next = tmp->next;
	free(tmp->content);
	free(tmp);
}
