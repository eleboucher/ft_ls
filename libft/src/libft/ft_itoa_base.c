/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 18:04:08 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/07 12:10:06 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_countdigit(int n, int base, size_t count)
{
	return (n > 0) ? ft_countdigit(n / base, base, count + 1) : count;
}

char			*ft_itoa_base(int n, int base)
{
	size_t	digit;
	char	*str;
	int		neg;

	neg = 0;
	if (n < 0)
	{
		if (base == 10)
			neg = 1;
		n *= -1;
	}
	digit = (n) ? ft_countdigit(n, base, 0) : 1;
	if (!(str = (char *)malloc(sizeof(char) * (digit + 1))))
		return (NULL);
	str[digit + neg] = 0;
	while (digit--)
	{
		str[digit + neg] = ft_abs(n % base) + (n % base > 9 ? 'A' - 10 : '0');
		n /= base;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
