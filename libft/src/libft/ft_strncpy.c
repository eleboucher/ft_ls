/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:32:14 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/06 11:56:13 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;
	char		*cpy;
	size_t		k;

	cpy = dst;
	i = 0;
	k = ft_strlen(src);
	while (i < len)
	{
		if (i < k)
			*(dst++) = *(src++);
		else
			*(dst++) = '\0';
		i++;
	}
	return (cpy);
}
