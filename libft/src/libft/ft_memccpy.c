/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:29:46 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/13 16:23:00 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*temp;
	const char	*source;

	temp = (char *)dst;
	source = (char *)src;
	while (n--)
	{
		if ((*(temp++) = *(source++)) == (char)c)
			return (temp);
	}
	return (0);
}
