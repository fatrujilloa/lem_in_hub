/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:09:45 by ftrujill          #+#    #+#             */
/*   Updated: 2019/06/22 16:56:57 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_llputnbr(long long nb)
{
	char		p[21];
	int			i;

	i = 0;
	p[i++] = nb < 0 ? '0' - nb % 10 : '0' + nb % 10;
	nb = nb / 10;
	while (nb != 0)
	{
		p[i++] = nb < 0 ? '0' - nb % 10 : '0' + nb % 10;
		nb = nb / 10;
	}
	p[i] = 0;
	ft_strrev(p);
	ft_putstr(p);
}

int			nb_len(long long nb)
{
	int i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int			unsigned_nb_len(unsigned long long nb)
{
	int i;

	i = nb == 0 ? 1 : 0;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void		reset_arg(t_arg *arg)
{
	int i;

	i = 0;
	arg->flag_hash = 0;
	arg->flag_zero = 0;
	arg->flag_minus = 0;
	arg->flag_space = 0;
	arg->flag_plus = 0;
	arg->width = 0;
	arg->prec = 0;
	i = 0;
	while (i < 3)
		arg->len_mod[i++] = 0;
	arg->conv = 0;
}

int			error(t_arg *arg, char *copy)
{
	free(arg);
	free(copy);
	return (0);
}
