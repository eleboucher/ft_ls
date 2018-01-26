/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 10:48:35 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/10 15:08:19 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	if (format)
	{
		va_start(ap, format);
		len = ft_print(format, ap);
		va_end(ap);
	}
	return (len);
}

int		ft_print(const char *format, va_list ap)
{
	int		len;
	int		tmp;
	char	*fmt;

	len = 0;
	fmt = (char *)format;
	while (*fmt)
	{
		while (*fmt && *fmt != '%')
		{
			len += write(1, fmt++, 1);
		}
		if (*fmt == '%')
		{
			if ((tmp = ft_proc_arg(&fmt, ap)) == -1)
				return (-1);
			len += tmp;
		}
	}
	return (len);
}
