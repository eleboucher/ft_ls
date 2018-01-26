/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 13:31:26 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/10 15:07:47 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			bigs_prec(wchar_t *s, t_prtf *data)
{
	int i;
	int prec;

	i = -1;
	prec = 0;
	while (s[++i])
	{
		if (prec + ft_wclen(s[i]) > data->precision)
			break ;
		else
			prec += ft_wclen(s[i]);
	}
	return (prec);
}

int					ft_formatbigc(t_prtf *data, va_list ap)
{
	wint_t	c;
	int		len;
	char	*str;

	c = va_arg(ap, wchar_t);
	if (!(ft_wclen(c)))
		return (-1);
	len = 0;
	if (!(str = ft_wctostr(c)))
		return (-1);
	if (data->fg_minus)
	{
		len += write(1, str, ft_wclen(c));
		len += ft_width(ft_wclen(c), data, str);
	}
	else
	{
		len += ft_width(ft_wclen(c), data, str);
		len += write(1, str, ft_wclen(c));
	}
	return (len);
}

int					ft_formatbigs(t_prtf *data, va_list ap)
{
	wchar_t	*s;
	int		size;
	char	*str;
	char	*tmp;

	size = -1;
	s = va_arg(ap, wchar_t *);
	data->fg_space = 0;
	data->fg_plus = 0;
	if (!s)
		return (ft_printstr(ft_strdup("(null)"), data));
	if (ft_wcslen(s) == -1)
		return (-1);
	if (!(str = ft_strnew(ft_wcslen(s))))
		return (-1);
	while (s[++size])
	{
		tmp = ft_wctostr(s[size]);
		ft_strcat(str, tmp);
		free(tmp);
	}
	if (data->precision != -1)
		data->precision = bigs_prec(s, data);
	return (ft_printstr(str, data));
}
