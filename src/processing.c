/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:02:51 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/05 09:48:49 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*get_info(char *dir, char *d_name)
{
	t_file *file;

	if (!(file = malloc(sizeof(t_file))))
		return (0);
	ft_strcpy(file->file_name, d_name);
	file->path = joindir(dir, d_name);
	lstat(file->path, &file->stat);
	file->dir = ft_strdup(dir);
	file->next = NULL;
	file->error = 0;
	file->inside = NULL;
	free(d_name);
	return (file);
}

char	*joindir(char *dir, char *newdir)
{
	dir = ft_strdup(dir);
	if (!ft_strcmp(dir, newdir))
		return (dir);
	if (ft_strcmp(dir, "/"))
		dir = ft_strcleanjoin(dir, "/");
	dir = ft_strcleanjoin(dir, newdir);
	return (dir);
}

t_file	*ft_getls(char *dir, t_ls *data)
{
	DIR				*rep;
	struct dirent	*readfile;
	t_file			*file;
	t_file			*cpy;

	cpy = NULL;
	if (!(rep = opendir(dir)))
		return (process_error(dir, (int)errno, data));
	while ((readfile = readdir(rep)))
	{
		if (cpy)
		{
			cpy->next = get_info(dir, ft_strdup(readfile->d_name));
			cpy = cpy->next;
		}
		else
		{
			cpy = get_info(dir, ft_strdup(readfile->d_name));
			file = cpy;
		}
	}
	closedir(rep);
	ft_mergesort(&file, data);
	file = (data->opts & FG_SR) ? reverse(file) : file;
	return (file);
}

int		process(t_ls *data)
{
	int	i;

	i = -1;
	if (!(data->files = malloc(sizeof(t_file) * (size_t)data->nb_dir + 1)))
		return (0);
	data->files[data->nb_dir] = 0;
	while (++i < data->nb_dir)
	{
		data->files[i] = ft_getls(data->dir[i], data);
	}
	if (data->alone_files)
	{
		ft_mergesort(&data->alone_files, data);
		data->alone_files = (data->opts & FG_SR) ? reverse(data->alone_files) :
			data->alone_files;
	}
	return (1);
}
