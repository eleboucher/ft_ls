/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:04:23 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/05 11:38:24 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_small(t_file *file, t_ls *data, int i)
{
	while (file)
	{
		if (!(!(data->opts & FG_A) && file->file_name[0] == '.'))
			display_file_name(file, data, i);
		file = file->next;
	}
}

void	display_long(t_file *file, t_ls *data, int i)
{
	t_size size;

	if (get_folder(file) && S_ISDIR(get_folder(file)->stat.st_mode))
		print_total(file, data->opts & FG_A);
	init_size(&size);
	maxsize_guid(file, &size, data->opts & FG_A);
	max_nlinknsize(file, &size, data->opts & FG_A);
	while (file)
	{
		if (!(!(data->opts & FG_A) && file->file_name[0] == '.'))
		{
			print_type(file, data->opts & FG_PLS);
			putpadnbr(file->stat.st_nlink, size.nlink, 0);
			print_guid(file, size);
			if (S_ISCHR(file->stat.st_mode) || S_ISBLK(file->stat.st_mode))
				print_majmin(file, size);
			else
				putpadnbr((size_t)file->stat.st_size, size.size, 0);
			print_date(file);
			display_file_name(file, data, i);
		}
		file = file->next;
	}
}

void	display_file(t_file *file, t_ls *data, int i)
{
	if (file->error)
		ft_putstr_fd(file->file_name, 2);
	else
	{
		(!(data->opts & FG_L)) ? display_small(file, data, i) :
			display_long(file, data, i);
	}
	if (data->opts & FG_BR)
		while (file)
		{
			if (ft_strcmp(file->file_name, ".") != 0
					&& ft_strcmp(file->file_name, "..") != 0 &&
					S_ISDIR(file->stat.st_mode) &&
					!(!(data->opts & FG_A) && file->file_name[0] == '.'))
			{
				file->inside = ft_getls(file->path, data);
				if (file->inside)
				{
					ft_printf("\n%s:\n", file->path);
					display_file(file->inside, data, i);
				}
			}
			file = file->next;
		}
}

void	display(t_ls *data)
{
	int		i;

	i = -1;
	if (data->nb_dir > 1)
		data->nb_dir = (!(data->opts & FG_T)) ? sortdirarr(&data->files,
				data->nb_dir - 1, &ascii_sort) : sortdirarr(&data->files,
					data->nb_dir - 1, &time_sort);
	if (data->alone_files)
		display_file(data->alone_files, data, i);
	if (data->nb_dir > 1 && data->opts & FG_SR)
		reverse_arr(&data->files, data->nb_dir);
	while (++i < data->nb_dir)
	{
		if (data->files[i] && data->nb_dir > 1 && (i > 0 || data->alone_files))
			ft_printf("\n");
		if (data->files[i] && data->nb_dir > 1 &&
				(!ft_strcmp(data->files[i]->dir, ".") || data->files[i]->error))
			ft_printf(".:\n");
		else if (data->files[i] && data->nb_dir > 1)
			ft_printf("%s:\n", data->files[i]->dir);
		if (data->files[i])
			display_file(data->files[i], data, i);
	}
}
