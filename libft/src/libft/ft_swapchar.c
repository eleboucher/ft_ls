/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:26:13 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/13 14:29:39 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapchar(char **arr, int a, int b)
{
	char *tmp;

	if (!arr)
		return ;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}
