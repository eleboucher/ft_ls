/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortarr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 07:15:49 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/31 11:19:49 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	swapfiles(t_file **files, int a, int b)
{
	t_file *tmp;

	if (!files)
		return ;
	tmp = files[a];
	files[a] = files[b];
	files[b] = tmp;
}

static int	partition(t_file **files, int begin, int end)
{
	t_file	*pivot;
	int		i;
	int		j;

	i = begin - 1;
	j = begin;
	pivot = files[end];
	while (j <= end - 1)
	{
		if (files[j] && pivot && ft_strcmp(files[j]->path, pivot->path) < 0)
		{
			i++;
			swapfiles(files, i, j);
		}
		j++;
	}
	swapfiles(files, (i + 1), end);
	return (i + 1);
}

void		ft_quicksortfiles(t_file **files, int begin, int end)
{
	int p;

	p = 0;
	if (!files || !*files)
		return ;
	if (begin < end)
	{
		p = partition(files, begin, end);
		ft_quicksortfiles(files, begin, p - 1);
		ft_quicksortfiles(files, p + 1, end);
	}
}
