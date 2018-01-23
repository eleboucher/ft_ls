/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:04:23 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/23 15:24:03 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void display_file (t_file *file, t_ls *data, int i)
{
	if (data->nb_dir > 1)
		ft_putendl(file->path);
    while (file)
    {
    	if (!data->fg_a && file->file_name[0] != '.')
    		ft_putendl(file->file_name);
    	else if (data->fg_a)
    		ft_putendl(file->file_name);
		if (data->fg_br && file->file_name[0] != '.')
		{
			file->inside = ft_getls(file->path);
			display_file(file->inside, data, i);
		}

    	file = file->next;
    }	
}

void	display(t_ls *data)
{
	t_file *file;
	int	i;

	i = -1;
	file = NULL;
	while (++i < data->nb_dir)
	{
		file = data->files[i];
		display_file(file, data, i);
	}
}
