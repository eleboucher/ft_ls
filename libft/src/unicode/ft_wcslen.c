/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 13:57:17 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/05 22:27:26 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wcslen(wchar_t *s)
{
	int size;

	size = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		if (!(ft_wclen(*s)))
			return (-1);
		size += ft_wclen(*s);
		s++;
	}
	return (size);
}
