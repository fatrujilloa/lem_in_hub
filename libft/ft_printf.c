/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:22:11 by ftrujill          #+#    #+#             */
/*   Updated: 2019/06/22 12:54:55 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conversions.h"

int		conv_pos(char c)
{
	int i;

	i = 0;
	while (c != g_conv_tab[i].conv)
		i++;
	return (i);
}

int		get_arg(const char *restrict *format_ptr, t_arg *arg)
{
	if (!(**format_ptr))
		return (0);
	if (!(arg_flag(format_ptr, arg))
		|| !(arg_width(format_ptr, arg))
		|| !(arg_prec(format_ptr, arg))
		|| !(arg_len_mod(format_ptr, arg))
		|| !(arg_conv(format_ptr, arg)))
		return (0);
	(*format_ptr)++;
	return (1);
}

int		nb_arg(const char *restrict format, ...)
{
	int i;

	i = 0;
	while (*format)
		if (*format++ == '%')
			i++;
	return (i);
}

int		print_result(char *str, t_arg *arg, va_list *ap, int j)
{
	int		i;
	int		(*f)(t_arg arg, va_list *ap);
	int		len;

	str[j] = 0;
	i = 0;
	j = 0;
	len = 0;
	while (str[j])
	{
		while (str[j] && str[j] != '%')
		{
			write(1, &str[j++], 1);
			len++;
		}
		if (!(str[j++]))
			break ;
		f = g_conv_tab[conv_pos(arg[i].conv)].f;
		len += f(arg[i++], ap);
	}
	free(str);
	free(arg);
	return (len);
}

int		ft_printf(const char *restrict format, ...)
{
	int		i;
	int		j;
	va_list	ap;
	t_arg	*arg;
	char	*copy;

	i = 0;
	j = 0;
	if (!(copy = (char*)malloc(ft_strlen(format) + 2)) ||
		!(arg = (t_arg*)malloc((nb_arg(format) + 1) * sizeof(t_arg))))
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		reset_arg(&arg[i]);
		while (*format && *format != '%')
			copy[j++] = *format++;
		copy[j++] = *format;
		if (!*format)
			break ;
		format++;
		if (!(get_arg(&(format), &arg[i++])))
			return (error(arg, copy));
	}
	return (print_result(copy, arg, &ap, j));
}
