/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:20:12 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/18 17:39:09 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getflags(char **fmt, t_prtf *data)
{
	data->fg_minus = 0;
	data->fg_zero = 0;
	while (**fmt && (**fmt == '#' || **fmt == ' ' || **fmt == '0'
			|| **fmt == '+' || **fmt == '-'))
	{
		if (**fmt == '#')
			data->fg_hashtag = 1;
		if (**fmt == ' ')
			data->fg_space = 1;
		if (**fmt == '0')
			data->fg_zero = 1;
		if (**fmt == '+')
			data->fg_plus = 1;
		if (**fmt == '-')
			data->fg_minus = 1;
		(*fmt)++;
	}
}

void	ft_initialize(t_prtf *data)
{
	data->fg_space = 0;
	data->fg_hashtag = 0;
	data->fg_plus = 0;
	data->precision = -1;
	data->neg = 0;
}
