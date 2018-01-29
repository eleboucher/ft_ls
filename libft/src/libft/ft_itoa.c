/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 18:04:08 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/29 11:01:19 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_countdigit(long n, int i)
{
	return ((n > 0)? ft_countdigit(n / 10, i + 1) : i);
}

char			*ft_itoa(int n)
{
	int		digit;
	long 	value;
	char	*str;
	int		neg;

	value = n;
	neg = 0;
	if (value < 0)
	{
		neg = 1;
		value *= -1;
	}
	digit = ft_countdigit(value, 0);
	if (!(str = (char *)malloc(sizeof(char) * (digit + neg + 1))))
		return (NULL);
	if (!value)
	{
		str[0] = '0';
		str[1] = 0;
		return (str);
	}
	str[digit + neg] = 0;
	while (digit--)
	{
		str[digit + neg] = n % 10 + '0';
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
