/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:52:50 by ftrujill          #+#    #+#             */
/*   Updated: 2019/06/22 17:05:19 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	rounding(long double nb, ssize_t prec)
{
	long double n;
	long double r;

	n = nb >= 0 ? nb - (long long)nb : -(nb - (long long)nb);
	r = 1.0;
	while (prec > 0)
	{
		n = 10 * n;
		r = r / 10;
		n = n - (long long)n;
		prec--;
	}
	if (n > 0.5)
		nb = nb >= 0 ? nb + r : nb - r;
	return (nb);
}

int			double_len(long double n)
{
	int i;

	if (n > -1.0 && n < 1.0)
		return (1);
	i = 0;
	while (n >= 1.0 || n <= -1.0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void		prt_double_intpart(long double n)
{
	int			i;
	int			k;
	long double	m;

	if (n > -1.0 && n < 1.0)
		write(1, "0", 1);
	while (n >= 1.0 || n <= -1.0)
	{
		m = n;
		i = 0;
		while ((m >= 10.0 || m <= -10.0) && i++ >= 0)
			m = m / 10;
		k = (int)m;
		k < 0 ? ft_putchar('0' - k) : ft_putchar('0' + k);
		m = 1;
		while (--i >= 0)
			m = 10 * m;
		n = n >= 0 ? n - k * m : -(n - k * m);
		m = m / 10;
		while (n <= m && m > 0.1)
		{
			write(1, "0", 1);
			m = m / 10;
		}
	}
}

void		prt_decimal(long double nb, ssize_t prec)
{
	write(1, ".", 1);
	nb = nb > 0 ? 10 * (nb - (long long)nb) : -10 * (nb - (long long)nb);
	while (prec > 0)
	{
		ft_putnbr((unsigned int)nb);
		nb = 10 * (nb - (long long)nb);
		prec--;
	}
}

int			ft_printarg_f(t_arg arg, va_list *ap)
{
	long double		nb;
	int				len;
	int				sign;

	nb = *arg.len_mod == 'L' ? va_arg(*ap, long double) : va_arg(*ap, double);
	sign = (nb < 0 || arg.flag_space || arg.flag_plus) ? 1 : 0;
	nb = rounding(nb, arg.prec);
	len = double_len(nb);
	len = (arg.prec != 0 || arg.flag_hash) ? len + 1 + arg.prec : len;
	if (!arg.flag_minus)
	{
		arg.flag_zero ? prt_sign_float(nb, arg) : prt_width(sign, len, arg);
		arg.flag_zero ? prt_width(sign, len, arg) : prt_sign_float(nb, arg);
	}
	arg.flag_minus ? prt_sign_float(nb, arg) : 0;
	prt_double_intpart(nb);
	(arg.flag_hash || arg.prec) ? prt_decimal(nb, arg.prec) : 0;
	arg.flag_minus ? prt_width(sign, len, arg) : 0;
	return (ft_max(arg.width, ft_max(arg.prec, len) + sign));
}
