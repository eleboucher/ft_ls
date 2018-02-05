/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freearr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:39:03 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/05 09:39:34 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		freearr(char ***arr)
{
	char	**file_name;
	int		i;

	file_name = *arr;
	i = -1;
	while (file_name[++i])
		free(file_name[i]);
	free(file_name);
}
