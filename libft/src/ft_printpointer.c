/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 00:07:52 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/05 00:26:56 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printpointer(t_prtf *data, va_list ap)
{
	size_t		value;

	value = va_arg(ap, size_t);
	data->fg_hashtag = 1;
	data->fg_space = 0;
	data->fg_plus = 0;
	return (ft_printstr(ft_strtolower(ft_lltoa_base(value, 16)), data));
}
