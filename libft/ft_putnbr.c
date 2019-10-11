/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:16:07 by ftrujill          #+#    #+#             */
/*   Updated: 2018/12/27 11:28:09 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	nb;
	char	p[12];
	char	sgn;
	int		i;

	nb = n;
	sgn = nb < 0 ? 1 : 0;
	nb = nb < 0 ? -nb : nb;
	p[0] = '0' + nb % 10;
	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		p[i++] = '0' + nb % 10;
	}
	if (sgn)
		p[i++] = '-';
	p[i] = 0;
	ft_strrev(p);
	ft_putstr(p);
}
