/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ovflw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:14:50 by ftrujill          #+#    #+#             */
/*   Updated: 2019/07/13 16:25:23 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Usual atoi which that works only for integers but returns a long long int.
** It returns 2147483648 if the number is ont in the INT range.
*/

long long int	ft_atoi_ovflw(const char *str)
{
	int					sgn;
	size_t				i;
	long long int		number;
	long long int		ovrflw;

	sgn = 1;
	i = 0;
	number = 0;
	ovrflw = 2147483648;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sgn = (str[i++] == '-') ? 0 : 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = 10 * number + str[i++] - 48;
		if ((sgn && ovrflw <= number) || (!sgn && ovrflw < number))
			return (ovrflw);
	}
	if (sgn == 0)
		number = -number;
	return ((int)number);
}
