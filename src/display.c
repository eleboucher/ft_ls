/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:04:23 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/15 16:48:43 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display(t_ls *data)
{
	t_file *file;
	int	i;

	i = -1;
	file = NULL;
	while (++i < data->nb_dir)
	{
		file = data->files[i];
		if (data->nb_dir > 1)
			ft_putendl(file->path);
		while (file)
		{
			if (!data->fg_a && file->file_name[0] != '.')
				ft_putendl(file->file_name);
			else if (data->fg_a)
				ft_putendl(file->file_name);
			file = file->next;
		}	
	}
}
