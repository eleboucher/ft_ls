/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:14:15 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/02 17:41:49 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_file(t_file **files)
{
	t_file *file;
	t_file *tmp;

	file = *files;
	while (file)
	{
		tmp = file->next;
		free(file->path);
		free(file->dir);
		if (file->inside != NULL)
			free_file(&file->inside);
		free(file);
		file = tmp;
	}
}

void	free_ls(t_ls **ls)
{
	t_ls	*data;
	int		i;

	data = *ls;
	i = -1;
	while (++i <= data->nb_dir)
		free(data->dir[i]);
	free(data->dir);
	i = -1;
	while (++i < data->nb_dir)
		if (data->files[i])
		free_file(&data->files[i]);
	free_file(&data->alone_files);
	free(data->files);
	free(data);
}
