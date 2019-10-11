/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 13:31:24 by ftrujill          #+#    #+#             */
/*   Updated: 2019/06/22 16:23:35 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prt_width(int sign, size_t len, t_arg arg)
{
	ssize_t	n;
	char	c;

	if (arg.width > ft_max(arg.prec, len) + sign)
	{
		c = arg.flag_zero && !(arg.flag_minus) ? '0' : ' ';
		n = arg.width - ft_max(arg.prec, len) - sign;
		while (n > 0)
		{
			write(1, &c, 1);
			n--;
		}
	}
}

void	prt_prec(ssize_t n)
{
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
}

void	prt_sign(long long nb, t_arg arg)
{
	nb < 0 ? write(1, "-", 1) : 0;
	nb >= 0 && arg.flag_space && !(arg.flag_plus) ? write(1, " ", 1) : 0;
	nb >= 0 && arg.flag_plus ? write(1, "+", 1) : 0;
}

void	prt_sign_float(long double nb, t_arg arg)
{
	nb < 0 ? write(1, "-", 1) : 0;
	nb >= 0 && arg.flag_space && !(arg.flag_plus) ? write(1, " ", 1) : 0;
	nb >= 0 && arg.flag_plus ? write(1, "+", 1) : 0;
}

void	prt_sign_base(int sign)
{
	if (sign == 1)
		write(1, "0", 1);
	if (sign == 2)
		write(1, "0x", 2);
	if (sign == 6)
		write(1, "0X", 2);
}
