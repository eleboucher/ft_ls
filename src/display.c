/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:04:23 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/29 16:28:20 by elebouch         ###   ########.fr       */
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
	mode_t mode;
	t_size size;

	print_total(file, data->fg_a);
	init_size(&size);
	maxsize_guid(file, &size, data->fg_a);
	max_nlinknsize(file, &size, data->fg_a);
	while (file)
	{
		if (!(!data->fg_a && file->file_name[0] == '.'))
		{
			mode = file->stat.st_mode;
			print_type(mode);
			print_right(mode);
			putpadnbr(file->stat.st_nlink, size.nlink + 1, 0);
			print_guid(file, size);
			if (S_ISCHR(mode) || S_ISBLK(mode))
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
	file = data->files[0];
	while (++i < data->nb_dir)
	{
		file = data->files[i];
		if (file && data->nb_dir != 1 && S_ISDIR(file->stat.st_mode))
			ft_printf("\n%s:\n", file->path);
		if (file)
			display_file(file, data, i);
	}
}
