/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesortchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:03:03 by elebouch          #+#    #+#             */
/*   Updated: 2017/11/13 14:29:56 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubblesortchar(char **arr)
{
	int		i;
	int		j;
	char	*temp;

	if (!arr)
		return ;
	i = ft_arrsize(arr) - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i - 1)
		{
			if (ft_strcmp(arr[j + 1], arr[j]) < 0)
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
