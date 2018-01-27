/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:04:23 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/27 12:32:53 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void display_small(t_file *file, t_ls *data)
{
	while (file)
	{
		if (!(!data->fg_a && file->file_name[0] == '.'))
			ft_printf("%s\n", file->file_name);
		file = file->next;
	}
}

void display_long(t_file *file, t_ls *data)
{
	mode_t mode;
	char *right;

	(void) data;
	while (file)
	{
		if (!(!data->fg_a && file->file_name[0] == '.'))
		{
			mode = file->stat.st_mode;
			right = print_right(mode);
			ft_printf("%c%s %2d %s\n", print_type(mode), right, file->stat.st_nlink,
					file->file_name);
		}
		file = file->next;
	}
}

void display_file (t_file *file, t_ls *data, int i)
{
	t_file *cpy;

	cpy = file;
	if (!data->fg_l)
		display_small(file, data);
	else
		display_long(file, data);
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
		if (data->nb_dir != 1 && S_ISDIR(file->stat.st_mode))
			ft_printf("\n%s:\n", file->path);
		display_file(file, data, i);
	}
}
