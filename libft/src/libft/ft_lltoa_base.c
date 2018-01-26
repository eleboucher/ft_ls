/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 18:04:08 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/18 18:17:04 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_countdigit(unsigned long long n, int base, size_t count)
{
	return (n > 0) ? ft_countdigit(n / base, base, count + 1) : count;
}

char			*ft_lltoa_base(unsigned long long n, int base)
{
	size_t	digit;
	char	*str;

	digit = (n) ? ft_countdigit(n, base, 0) : 1;
	if (!(str = (char *)malloc(sizeof(char) * (digit + 1))))
		return (NULL);
	str[digit] = '\0';
	while (digit--)
	{
		str[digit] = ft_abs(n % base) + (n % base > 9 ? 'A' - 10 : '0');
		n /= base;
	}
	return (str);
}
