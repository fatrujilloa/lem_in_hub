/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:11:26 by ftrujill          #+#    #+#             */
/*   Updated: 2019/06/22 16:56:58 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printarg_pcnt(t_arg arg, va_list *ap)
{
	(void)ap;
	arg.flag_minus ? 0 : prt_width(0, 1, arg);
	write(1, "%", 1);
	arg.flag_minus ? prt_width(0, 1, arg) : 0;
	return (ft_max(arg.width, 1));
}

int		ft_printarg_c(t_arg arg, va_list *ap)
{
	char c;

	c = (char)va_arg(*ap, int);
	arg.flag_minus ? 0 : prt_width(0, 1, arg);
	write(1, &c, 1);
	arg.flag_minus ? prt_width(0, 1, arg) : 0;
	return (ft_max(arg.width, 1));
}

int		ft_printarg_s(t_arg arg, va_list *ap)
{
	char	*str;
	size_t	len;

	str = va_arg(*ap, char*);
	if (str)
		len = arg.prec != -1 ? ft_min(ft_strlen(str), arg.prec)
		: ft_strlen(str);
	else
		len = arg.prec != -1 ? ft_min(6, arg.prec) : 6;
	arg.prec = 0;
	arg.flag_minus ? 0 : prt_width(0, len, arg);
	str ? ft_putnstr(str, len) : write(1, "(null)", len);
	arg.flag_minus ? prt_width(0, len, arg) : 0;
	return (ft_max(arg.width, len));
}

int		ft_printarg_p(t_arg arg, va_list *ap)
{
	unsigned long long	nb;
	int					len;
	char				*str;
	int					sign;

	nb = va_arg(*ap, unsigned long);
	str = ft_strlower(ft_itoa_base(nb, 16));
	len = (*str == '0' && arg.prec == 0) ? 0 : ft_strlen(str);
	sign = 2;
	if (!arg.flag_minus)
	{
		arg.flag_zero ? prt_sign_base(sign) : prt_width(sign, len, arg);
		arg.flag_zero ? prt_width(sign, len, arg) : prt_sign_base(sign);
	}
	arg.flag_minus ? prt_sign_base(sign) : 0;
	arg.prec > len ? prt_prec(arg.prec - len) : 0;
	len ? ft_putstr(str) : 0;
	free(str);
	arg.flag_minus ? prt_width(sign, len, arg) : 0;
	return (ft_max(arg.width, ft_max(arg.prec, len) + sign));
}

int		ft_printarg_d(t_arg arg, va_list *ap)
{
	long long		nb;
	int				len;
	int				sign;

	nb = va_arg(*ap, long long);
	if (!(*arg.len_mod))
		nb = (int)nb;
	else if (*arg.len_mod == 'h')
		nb = arg.len_mod[1] == 'h' ? (signed char)nb : (short)nb;
	else if (*arg.len_mod == 'l')
		nb = arg.len_mod[1] == 'l' ? nb : (long)nb;
	len = (nb == 0 && arg.prec == 0) ? 0 : nb_len(nb);
	sign = (nb < 0 || arg.flag_space || arg.flag_plus) ? 1 : 0;
	if (!arg.flag_minus)
	{
		arg.flag_zero ? prt_sign(nb, arg) : prt_width(sign, len, arg);
		arg.flag_zero ? prt_width(sign, len, arg) : prt_sign(nb, arg);
	}
	arg.flag_minus ? prt_sign(nb, arg) : 0;
	arg.prec > len ? prt_prec(arg.prec - len) : 0;
	len ? ft_llputnbr(nb) : 0;
	arg.flag_minus ? prt_width(sign, len, arg) : 0;
	return (ft_max(arg.width, ft_max(arg.prec, len) + sign));
}
