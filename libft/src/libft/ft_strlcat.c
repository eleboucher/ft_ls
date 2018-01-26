/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:31:56 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/06 11:53:22 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		dst_len;

	d = dst;
	n = size;
	s = src;
	while (n-- != 0 && *d != '\0')
		d++;
	dst_len = d - dst;
	n = size - dst_len;
	if (n == 0)
		return (dst_len + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*(d++) = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dst_len + (s - src));
}
