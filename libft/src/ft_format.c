/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:08:36 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/10 15:09:13 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_formatstr(t_prtf *data, va_list ap)
{
	char	*s;

	if (data->format == 'S' || (data->format == 's' && data->modifier == md_l))
		return (ft_formatbigs(data, ap));
	s = va_arg(ap, char *);
	data->fg_space = 0;
	data->fg_plus = 0;
	if (!s)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(s);
	if (data->format == 's')
		return (ft_printstr(s, data));
	return (0);
}

int		ft_formatchr(t_prtf *data, va_list ap)
{
	char	c;
	int		len;

	len = 0;
	if (data->format == 'C' || (data->format == 'c' && data->modifier == md_l))
		return (ft_formatbigc(data, ap));
	c = va_arg(ap, int);
	if (data->fg_minus)
	{
		len += write(1, &c, 1);
		len += ft_width(1, data, ft_ctos(c));
	}
	else
	{
		len += ft_width(1, data, ft_ctos(c));
		len += write(1, &c, 1);
	}
	return (len);
}

int		ft_formatint(t_prtf *data, va_list ap)
{
	long long i;

	if (data->modifier == md_h)
		i = (short)va_arg(ap, int);
	else if (data->modifier == md_db_h)
		i = (signed char)va_arg(ap, long long);
	else if (data->modifier == md_l)
		i = (long)va_arg(ap, long long);
	else if (data->modifier == md_db_l)
		i = (long long)va_arg(ap, long long);
	else if (data->modifier == md_j)
		i = (intmax_t)va_arg(ap, long long);
	else if (data->modifier == md_z)
		i = (size_t)va_arg(ap, long long);
	else
		i = (int)va_arg(ap, long long int);
	if (i < 0)
	{
		data->neg = 1;
		i *= -1;
	}
	return (ft_printstr(ft_lltoa_base(i, 10), data));
}

int		ft_formatuint(t_prtf *data, va_list ap)
{
	unsigned long long i;

	if (data->modifier == md_db_h)
		i = (unsigned char)va_arg(ap, unsigned long long int);
	else if (data->modifier == md_h)
		i = (unsigned short int)va_arg(ap, unsigned long long int);
	else if (data->modifier == md_l)
		i = (unsigned long)va_arg(ap, unsigned long long int);
	else if (data->modifier == md_db_l)
		i = va_arg(ap, unsigned long long int);
	else if (data->modifier == md_j)
		i = (uintmax_t)va_arg(ap, unsigned long long int);
	else if (data->modifier == md_z)
		i = (size_t)va_arg(ap, unsigned long long int);
	else
		i = (unsigned int)va_arg(ap, unsigned long long int);
	data->fg_space = 0;
	data->fg_plus = 0;
	if (data->format == 'x')
		return (ft_printstr(ft_strtolower(ft_lltoa_base(i, 16)), data));
	if (data->format == 'X')
		return (ft_printstr(ft_lltoa_base(i, 16), data));
	if (data->format == 'o')
		return (ft_printstr(ft_lltoa_base(i, 8), data));
	return (ft_printstr(ft_lltoa_base(i, 10), data));
}

int		ft_formatlong(t_prtf *data, va_list ap)
{
	long long int		i;
	unsigned long long	ui;

	ui = 0;
	if (data->format == 'D')
	{
		i = va_arg(ap, long int);
		if (i < 0)
		{
			data->neg = 1;
			i *= -1;
		}
		return (ft_printstr(ft_lltoa_base(i, 10), data));
	}
	i = 0;
	ui = (unsigned long int)va_arg(ap, long int);
	data->fg_space = 0;
	data->fg_plus = 0;
	if (data->format == 'O')
		return (ft_printstr(ft_lltoa_base(ui, 8), data));
	return (ft_printstr(ft_lltoa_base(ui, 10), data));
}
