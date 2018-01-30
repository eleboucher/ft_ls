/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:04:23 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/30 07:26:59 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void display_small(t_file *file, t_ls *data)
{
	while (file)
	{
		if (!(!data->fg_a && file->file_name[0] == '.'))
			display_file_name(file, data);
		file = file->next;
	}
}


void display_long(t_file *file, t_ls *data)
{
	t_size size;

	if (S_ISDIR(file->stat.st_mode))
		print_total(file, data->fg_a);
	init_size(&size);
	maxsize_guid(file, &size, data->fg_a);
	max_nlinknsize(file, &size, data->fg_a);
	while (file)
	{
		if (!(!data->fg_a && file->file_name[0] == '.'))
		{
			print_type(file->stat.st_mode);
			print_right(file->stat.st_mode);
			putpadnbr(file->stat.st_nlink, size.nlink + 1, 0);
			print_guid(file, size);
			if (S_ISCHR(file->stat.st_mode) || S_ISBLK(file->stat.st_mode))
				print_majmin(file, size);
			else
				putpadnbr(file->stat.st_size, size.size, 0);
			print_date(file);
			ft_putchar(' ');
			display_file_name(file, data);
		}
		file = file->next;
	}
}

void display_file (t_file *file, t_ls *data, int i)
{
	if (file->error)
		ft_putstr_fd(file->file_name, 2);
	else
	{
		if (!data->fg_l)
			display_small(file, data);
		else
			display_long(file, data);
	}
	if (data->fg_br)
		while (file)
		{
			if (data->fg_br && (ft_strcmp(file->file_name, ".") != 0 
						&& ft_strcmp(file->file_name, "..") != 0) &&
					S_ISDIR(file->stat.st_mode) && (data->fg_a || 
						(!data->fg_a && file->file_name[0] != '.')))
			{
				ft_printf("\n%s:\n", file->path);
				file->inside = ft_getls(file->path, data);
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
	if (data->nb_dir > 1)
		ft_quicksortfiles(data->files, 0, data->nb_dir - 1);
	file = data->files[0];
	while (++i < data->nb_dir)
	{
		file = data->files[i];
		if (file && data->nb_dir != 1 && (S_ISDIR(file->stat.st_mode) ||
					file->error))
			ft_printf("\n%s:\n", file->path);
		if (file)
			display_file(file, data, i);
	}
}
