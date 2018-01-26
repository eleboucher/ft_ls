/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:42:39 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/13 14:59:15 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printbits(int n, int digits)
{
	if (digits == 0)
		return ;
	ft_printbits(n / 2, digits - 1);
	ft_putchar('0' + n % 2);
}

void		ft_putbits(const char byte)
{
	ft_printbits(byte, 8);
}
