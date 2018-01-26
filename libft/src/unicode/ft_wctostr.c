/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 00:13:12 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/08 11:46:43 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wctostr(wchar_t c)
{
	char *str;

	if (!(str = ft_strnew(ft_wclen(c))))
		return (NULL);
	if ((c <= 0x7F && MB_CUR_MAX >= 1) || (c <= 0xFF && MB_CUR_MAX == 1))
		str[0] = (unsigned char)c;
	else if (c <= 0x7FF && MB_CUR_MAX >= 2)
	{
		str[0] = (c >> 6) | 0xC0;
		str[1] = (c & 0x3F) | 0x80;
	}
	else if (c <= 0xFFFF && MB_CUR_MAX >= 3)
	{
		str[0] = (c >> 12) | 0xE0;
		str[1] = (c >> 6 & 0x3F) | 0x80;
		str[2] = (c & 0x3F) | 0x80;
	}
	else if (c <= 0x10FFFF && MB_CUR_MAX >= 4)
	{
		str[0] = (c >> 18) | 0xF0;
		str[1] = (c >> 12 & 0x3F) | 0x80;
		str[2] = (c >> 6 & 0x3F) | 0x80;
		str[3] = (c & 0x3F) | 0x80;
	}
	return (str);
}
