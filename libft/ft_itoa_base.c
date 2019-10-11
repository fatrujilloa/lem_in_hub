/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:49:32 by ftrujill          #+#    #+#             */
/*   Updated: 2019/07/12 14:57:14 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	base_element(int n)
{
	if (n < 10)
		return ('0' + n);
	else
		return ('A' + n - 10);
}

int		conversion_size(unsigned long long value, int base)
{
	int size;

	if (value == 0)
		return (2);
	size = 1;
	while (value > 0)
	{
		value = value / base;
		size++;
	}
	return (size + 1);
}

char	*ft_itoa_base(unsigned long long value, int base)
{
	char	*p;
	int		i;

	if (base <= 1 || base >= 17)
		return (0);
	if (!(p = (char*)malloc(conversion_size(value, base))))
		return (0);
	i = 0;
	p[i] = base_element(value % base);
	i++;
	while (value / base > 0)
	{
		value = value / base;
		p[i] = base_element(value % base);
		i++;
	}
	p[i] = 0;
	ft_strrev(p);
	return (p);
}
