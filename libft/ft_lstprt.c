/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:17:31 by ftrujill          #+#    #+#             */
/*   Updated: 2018/11/18 16:28:01 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprt(t_list *lst)
{
	while (lst)
	{
		ft_putnstr((char*)lst->content, lst->content_size);
		ft_putstr("\n");
		lst = lst->next;
	}
}
