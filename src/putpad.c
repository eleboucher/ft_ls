/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:16:50 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/30 18:46:10 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	putpadstr(char *str, size_t n, int fg_minus)
{
	n = n - ft_strlen(str) + 1;
	write(1, " ", 1);
	if (fg_minus)
		write(1, str, ft_strlen(str));
	while (n--)
		write(1, " ", 1);
	if (!(fg_minus))
		write(1, str, ft_strlen(str));
}

void	putpadnbr(size_t value, size_t n, int fg_minus)
{
	char *str;

	write(1, " ", 1);
	str = ft_lltoa_base(value, 10);
	n = n - ft_strlen(str);
	if (fg_minus)
		write(1, str, ft_strlen(str));
	while (n--)
		write(1, " ", 1);
	if (!fg_minus)
		write(1, str, ft_strlen(str));
	free(str);
}
