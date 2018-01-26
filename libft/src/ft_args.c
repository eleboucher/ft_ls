/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:11:43 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/10 15:09:23 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_proc_arg(char **fmt, va_list ap)
{
	t_prtf			data;

	if (**fmt == '%')
	{
		(*fmt)++;
		if (**fmt)
		{
			*fmt = ft_parse_args(&data, fmt);
			return (ft_print_args(&data, ap));
		}
	}
	return (0);
}

char	*ft_parse_args(t_prtf *data, char **fmt)
{
	ft_initialize(data);
	data->width = -1;
	ft_getflags(fmt, data);
	if (ft_isdigit(**fmt))
		data->width = ft_parse_intarg(fmt);
	if (**fmt == '.')
	{
		(*fmt)++;
		data->precision = ft_parse_intarg(fmt);
	}
	data->modifier = ft_parse_mod(fmt);
	while (ft_isspace(**fmt))
		(*fmt)++;
	data->format = **fmt;
	if (**fmt)
		(*fmt)++;
	return (*fmt);
}

int		ft_parse_intarg(char **fmt)
{
	unsigned int ret;

	ret = 0;
	while (**fmt != '\0')
	{
		if (!ft_isdigit(**fmt))
			break ;
		ret = ret * 10 + *(*fmt)++ - '0';
	}
	return (ret);
}

int		ft_parse_mod(char **fmt)
{
	int ret;

	ret = none;
	if (**fmt == 'l')
	{
		ret = md_l;
		if (*(*fmt)++ && **fmt == 'l')
			ret = md_db_l;
	}
	if (**fmt == 'h')
	{
		ret = md_h;
		if (*(*fmt)++ && **fmt == 'h')
			ret = md_db_h;
	}
	if (**fmt == 'j')
		ret = md_j;
	if (**fmt == 'z')
		ret = md_z;
	if (*fmt && ret != none && ret != md_l && ret != md_h)
		(*fmt)++;
	return (ret);
}

int		ft_print_args(t_prtf *data, va_list ap)
{
	if (data->format == 's' || data->format == 'S')
		return (ft_formatstr(data, ap));
	else if (data->format == 'c' || data->format == 'C')
		return (ft_formatchr(data, ap));
	else if (data->format == 'd' || data->format == 'i')
		return (ft_formatint(data, ap));
	else if (data->format == 'o' || data->format == 'u' || data->format == 'x'
			|| data->format == 'X')
		return (ft_formatuint(data, ap));
	else if (data->format == 'D' || data->format == 'O' || data->format == 'U')
		return (ft_formatlong(data, ap));
	else if (data->format == 'p')
		return (ft_printpointer(data, ap));
	ft_initialize(data);
	return (ft_printstr(ft_ctos(data->format), data));
}
