/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesortint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:05:35 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/13 14:17:54 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubblesortint(int *arr, size_t len)
{
	size_t	i;
	size_t	j;
	int		temp;

	if (!arr)
		return ;
	i = len - 1;
	while (i > 0)
	{
		j = 0;
		while (j <= i - 1)
		{
			if (arr[j + 1] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i--;
	}
}
