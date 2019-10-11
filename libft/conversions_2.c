/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:13:18 by ftrujill          #+#    #+#             */
/*   Updated: 2019/06/22 12:55:23 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_printarg_i(t_arg arg, va_list *ap)
{
	return (ft_printarg_d(arg, ap));
}

int		ft_printarg_o(t_arg arg, va_list *ap)
{
	unsigned long long	nb;
	ssize_t				len;
	char				*str;
	int					s;

	nb = va_arg(*ap, unsigned long long);
	nb = !(*arg.len_mod) ? (unsigned int)nb : nb;
	if (*arg.len_mod == 'h')
		nb = arg.len_mod[1] == 'h' ? (unsigned char)nb : (unsigned short)nb;
	else if (*arg.len_mod == 'l')
		nb = arg.len_mod[1] == 'l' ? nb : (unsigned long)nb;
	str = ft_itoa_base(nb, 8);
	len = (*str == '0' && arg.prec == 0) ? 0 : ft_strlen(str);
	s = arg.flag_hash && len >= arg.prec && (*str != '0' || !arg.prec) ? 1 : 0;
	if (!arg.flag_minus)
	{
		arg.flag_zero ? prt_sign_base(s) : prt_width(s, len, arg);
		arg.flag_zero ? prt_width(s, len, arg) : prt_sign_base(s);
	}
	arg.flag_minus ? prt_sign_base(s) : 0;
	arg.prec > len ? prt_prec(arg.prec - len) : 0;
	len ? ft_putstr(str) : 0;
	free(str);
	arg.flag_minus ? prt_width(s, len, arg) : 0;
	return (ft_max(arg.width, ft_max(arg.prec, len) + s));
}

int		ft_printarg_u(t_arg arg, va_list *ap)
{
	unsigned long long			nb;
	int							len;
	char						*str;

	nb = va_arg(*ap, unsigned long long);
	if (!(*arg.len_mod))
		nb = (unsigned int)nb;
	else if (*arg.len_mod == 'h')
		nb = arg.len_mod[1] == 'h' ? (unsigned char)nb : (unsigned short)nb;
	else if (*arg.len_mod == 'l')
		nb = arg.len_mod[1] == 'l' ? nb : (unsigned long)nb;
	str = ft_itoa_base(nb, 10);
	len = (*str == '0' && arg.prec == 0) ? 0 : ft_strlen(str);
	arg.flag_minus ? 0 : prt_width(0, len, arg);
	arg.prec > len ? prt_prec(arg.prec - len) : 0;
	len ? ft_putstr(str) : 0;
	free(str);
	arg.flag_minus ? prt_width(0, len, arg) : 0;
	return (ft_max(arg.width, ft_max(arg.prec, len)));
}

int		ft_printarg_x(t_arg arg, va_list *ap)
{
	unsigned long long	nb;
	int					len;
	char				*str;
	int					sign;

	nb = va_arg(*ap, unsigned long long);
	nb = !(*arg.len_mod) ? (unsigned int)nb : nb;
	if (*arg.len_mod == 'h')
		nb = arg.len_mod[1] == 'h' ? (unsigned char)nb : (unsigned short)nb;
	else if (*arg.len_mod == 'l')
		nb = arg.len_mod[1] == 'l' ? nb : (unsigned long)nb;
	str = ft_strlower(ft_itoa_base(nb, 16));
	len = (*str == '0' && arg.prec == 0) ? 0 : ft_strlen(str);
	sign = arg.flag_hash && *str != '0' ? 2 : 0;
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

int		ft_printarg_big_x(t_arg arg, va_list *ap)
{
	unsigned long long	nb;
	int					len;
	char				*str;
	int					sign;

	nb = va_arg(*ap, unsigned long long);
	nb = !(*arg.len_mod) ? (unsigned int)nb : nb;
	if (*arg.len_mod == 'h')
		nb = arg.len_mod[1] == 'h' ? (unsigned char)nb : (unsigned short)nb;
	else if (*arg.len_mod == 'l')
		nb = arg.len_mod[1] == 'l' ? nb : (unsigned long)nb;
	str = ft_itoa_base(nb, 16);
	len = (*str == '0' && arg.prec == 0) ? 0 : ft_strlen(str);
	sign = arg.flag_hash && *str != '0' ? 2 : 0;
	if (!arg.flag_minus)
	{
		arg.flag_zero ? prt_sign_base(sign + 4) : prt_width(sign, len, arg);
		arg.flag_zero ? prt_width(sign, len, arg) : prt_sign_base(sign + 4);
	}
	arg.flag_minus ? prt_sign_base(sign + 4) : 0;
	arg.prec > len ? prt_prec(arg.prec - len) : 0;
	len ? ft_putstr(str) : 0;
	free(str);
	arg.flag_minus ? prt_width(sign, len, arg) : 0;
	return (ft_max(arg.width, ft_max(arg.prec, len) + sign));
}
