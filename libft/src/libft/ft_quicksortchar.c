/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksortchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:24:24 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/13 14:56:57 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	partition(char **arr, int begin, int end)
{
	char	*pivot;
	int		i;
	int		j;

	i = begin - 1;
	j = begin;
	pivot = arr[end];
	while (j <= end - 1)
	{
		if (ft_strcmp(arr[j], pivot) < 0)
		{
			i++;
			ft_swapchar(arr, i, j);
		}
		j++;
	}
	ft_swapchar(arr, (i + 1), end);
	return (i + 1);
}

void		ft_quicksortchar(char **arr, int begin, int end)
{
	int p;

	p = 0;
	if (!arr)
		return ;
	if (begin < end)
	{
		p = partition(arr, begin, end);
		ft_quicksortchar(arr, begin, p - 1);
		ft_quicksortchar(arr, p + 1, end);
	}
}
