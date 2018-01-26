/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksortint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:04:30 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/13 14:19:04 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	partition(int *arr, int begin, int end)
{
	int pivot;
	int i;
	int j;

	i = begin - 1;
	j = begin;
	pivot = arr[end];
	while (j <= end - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			ft_swapint(arr, (i), (j));
		}
		j++;
	}
	ft_swapint(arr, (i + 1), end);
	return (i + 1);
}

void		ft_quicksortint(int *arr, int begin, int end)
{
	int p;

	p = 0;
	if (!arr)
		return ;
	if (begin < end)
	{
		p = partition(arr, begin, end);
		ft_quicksortint(arr, begin, p - 1);
		ft_quicksortint(arr, p + 1, end);
	}
}
