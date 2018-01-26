/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 17:45:42 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/06 11:29:45 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*newmem;

	if ((newmem = malloc(size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		newmem[i++] = 0;
	return ((void *)newmem);
}
