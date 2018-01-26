/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 18:04:08 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/14 09:55:43 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbdigit(int n)
{
	size_t count;

	count = (n < 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		++count;
	}
	return (count);
}

static char		*ft_case_zero(void)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = '0';
	str[1] = 0;
	return (str);
}

char			*ft_itoa(int n)
{
	size_t	digit;
	char	*str;

	if (!n)
		return (ft_case_zero());
	digit = ft_nbdigit(n);
	if (!(str = (char *)malloc(sizeof(char) * (digit + 1))))
		return (NULL);
	str[digit] = 0;
	while (digit-- && n)
	{
		str[digit] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (digit == 0)
		str[digit] = '-';
	return (str);
}
