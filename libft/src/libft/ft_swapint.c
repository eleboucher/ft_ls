/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:16:25 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/13 14:29:04 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapint(int *arr, int a, int b)
{
	int tmp;

	if (!arr)
		return ;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}
