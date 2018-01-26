/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:32:27 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/06 11:59:10 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*p1;
	const char	*p2;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			p1 = haystack;
			p2 = needle;
			while (*p1 && *p2 && *p1 == *p2)
			{
				++p1;
				++p2;
			}
			if (!*p2)
				return ((char*)haystack);
		}
		++haystack;
	}
	return (0);
}
