/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:04:23 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/26 14:46:29 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void display_file (t_file *file, t_ls *data, int i)
{
	t_file *cpy;

	cpy = file;
	while (file)
	{
		if (!data->fg_a && file->file_name[0] != '.')
			ft_printf("%s\n", file->file_name);
		else if (data->fg_a)
			ft_printf("%s\n", file->file_name);
		file = file->next;
	}
	if (data->fg_br)
		while (cpy)
		{
			if (data->fg_br && (ft_strcmp(cpy->file_name, ".") != 0 
						&& ft_strcmp(cpy->file_name, "..") != 0) &&
					S_ISDIR(cpy->stat.st_mode) && (data->fg_a || 
						(!data->fg_a && cpy->file_name[0] != '.')))
			{
				ft_printf("\n%s:\n", cpy->path);
				cpy->inside = ft_getls(cpy->path);
				display_file(cpy->inside, data, i);
			}
			cpy = cpy->next;
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
