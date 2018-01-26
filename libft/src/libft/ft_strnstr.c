/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:32:18 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/07 17:31:26 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = ft_strlen(needle);
	if (!ft_strlen(haystack))
		return (NULL);
	if (!i)
		return ((char *)haystack);
	while (len-- >= i && *haystack)
	{
		if (!ft_strncmp((char*)haystack, (char*)needle, i))
			return ((char*)haystack);
		haystack++;
	}
	return (0);
}
