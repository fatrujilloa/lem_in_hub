/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 13:56:32 by ftrujill          #+#    #+#             */
/*   Updated: 2019/06/22 16:23:51 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct	s_arg
{
	char	flag_hash;
	char	flag_zero;
	char	flag_minus;
	char	flag_space;
	char	flag_plus;
	ssize_t	width;
	ssize_t	prec;
	char	len_mod[3];
	char	conv;
}				t_arg;

typedef struct	s_conv
{
	char	conv;
	int		(*f)(t_arg arg, va_list *ap);
}				t_conv;

/*
** Prototype ft_printf
*/
int				ft_printf(const char *restrict format, ...);
/*
** Print functions
*/
int				ft_printarg_c(t_arg arg, va_list *ap);
int				ft_printarg_s(t_arg arg, va_list *ap);
int				ft_printarg_p(t_arg arg, va_list *ap);
int				ft_printarg_d(t_arg arg, va_list *ap);
int				ft_printarg_i(t_arg arg, va_list *ap);
int				ft_printarg_o(t_arg arg, va_list *ap);
int				ft_printarg_u(t_arg arg, va_list *ap);
int				ft_printarg_x(t_arg arg, va_list *ap);
int				ft_printarg_big_x(t_arg arg, va_list *ap);
int				ft_printarg_f(t_arg arg, va_list *ap);
int				ft_printarg_pcnt(t_arg arg, va_list *ap);
/*
** Get Argument
*/
int				arg_flag(const char *restrict *f, t_arg *arg);
int				arg_width(const char *restrict *f, t_arg *arg);
int				arg_prec(const char *restrict *f, t_arg *arg);
int				arg_len_mod(const char *restrict *f, t_arg *arg);
char			arg_conv(const char *restrict *f, t_arg *arg);
/*
** Aux functions
*/
void			ft_llputnbr(long long nb);
int				nb_len(long long nb);
int				unsigned_nb_len(unsigned long long nb);
void			reset_arg(t_arg *arg);
int				error(t_arg *arg, char *copy);
/*
** Aux print functions
*/
void			prt_width(int sign, size_t len, t_arg arg);
void			prt_prec(ssize_t n);
void			prt_sign(long long nb, t_arg arg);
void			prt_sign_float(long double nb, t_arg arg);
void			prt_sign_base(int sign);

#endif
