/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:27:52 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/07 17:42:58 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	result;
	unsigned int	sign;

	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		str++;
		sign = 1;
	}
	else
	{
		sign = 0;
		if (*str == '+')
			str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			break ;
		result = result * 10 + *(str++) - '0';
	}
	return ((sign) ? -result : result);
}
