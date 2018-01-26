/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:36:35 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/15 10:54:11 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printstr(char *str, t_prtf *data)
{
	int size;

	size = 0;
	str = (data->precision == -1) ? str : ft_precision(str, data);
	if (data->fg_zero && !data->fg_minus)
	{
		size += ft_prefix(str, data);
		size += ft_width(ft_strlen(str), data, str);
		size += write(1, str, ft_strlen(str));
	}
	else if (data->fg_minus)
	{
		size += ft_prefix(str, data);
		size += write(1, str, ft_strlen(str));
		size += ft_width(ft_strlen(str), data, str);
	}
	else
	{
		size += ft_width(ft_strlen(str), data, str);
		size += ft_prefix(str, data);
		size += write(1, str, ft_strlen(str));
	}
	free(str);
	return (size);
}

char	*ft_precision(char *str, t_prtf *data)
{
	int		len;
	char	*s;

	len = ft_max(data->precision, ft_strlen(str)) - ft_strlen(str);
	if (data->format == 'o' && data->fg_hashtag && len > 0)
		len -= 1;
	if (len <= 0 && str[0] == '0')
	{
		free(str);
		s = ft_strnew(0);
		return (s);
	}
	if (data->format == 's' || data->format == 'S')
	{
		s = ft_strsub(str, 0, data->precision);
		return (s);
	}
	s = ft_strnew(data->precision);
	ft_strset(s, '0', 0, len);
	s = ft_strcat(s, str);
	free(str);
	return (s);
}

int		ft_width(size_t len, t_prtf *data, char *str)
{
	int		size;
	char	*pad;

	size = ft_max(data->width, len) - len;
	size = ft_getwidthsize(size, data, str);
	if (size <= 0)
		return (0);
	pad = ft_strnew(size);
	if (data->fg_zero && !data->fg_minus && data->precision <= 0)
	{
		ft_strset(pad, '0', 0, size);
		size = write(1, pad, size);
	}
	else
	{
		ft_strset(pad, ' ', 0, size);
		size = write(1, pad, size);
	}
	free(pad);
	return (size);
}

int		ft_prefix(char *str, t_prtf *data)
{
	int size;

	size = 0;
	if ((data->format == 'o' || data->format == 'O') && data->fg_hashtag &&
			((str[0] != '0' && *str) || data->precision >= 0))
		size += write(1, "0", 1);
	if (data->format == 'p' || (data->format == 'x' && data->fg_hashtag &&
				((*str && str[0] != '0') || data->precision > 0)))
		size += write(1, "0x", 2);
	if (data->format == 'X' && data->fg_hashtag &&
			((*str && str[0] != '0') || data->precision > 0))
		size += write(1, "0X", 2);
	if (data->neg)
		size += write(1, "-", 1);
	if (!data->neg && data->fg_plus)
		size += write(1, "+", 1);
	if (!data->neg && !data->fg_plus && data->fg_space &&
			data->format != '%')
		size += write(1, " ", 1);
	return (size);
}

int		ft_getwidthsize(int len, t_prtf *data, char *str)
{
	if ((data->format == 'o' || data->format == 'O') && data->fg_hashtag &&
			((str[0] != '0' && *str) || data->precision >= 0))
		len -= 1;
	if (data->format == 'p' || (data->format == 'x' && data->fg_hashtag &&
			((str[0] != '0' && *str) || data->precision >= 0)))
		len -= 2;
	if (data->format == 'X' && data->fg_hashtag &&
			((str[0] != '0' && *str) || data->precision >= 0))
		len -= 2;
	if (data->neg || (!data->neg && data->fg_plus) || (!data->neg &&
				!data->fg_plus && data->fg_space && data->format != '%'))
		len -= 1;
	return (len);
}
