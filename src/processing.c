/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:02:51 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/29 16:44:29 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file 	*get_info(char *dir, char *d_name)
{
	t_file *file;

	if (!(file = malloc(sizeof(t_file))))
		return (0);
	ft_strcpy(file->file_name, d_name);
	file->path = joindir(dir, d_name);
	lstat(file->path, &file->stat);
	file->isdir = 0;
	file->next = NULL;
	file->error = NULL;
	file->inside = NULL;
	return (file);
}

char *joindir(char *dir,char *newdir)
{
	dir = ft_strdup(dir);
	if (!ft_strcmp(dir, newdir))
		return (dir);
	if (ft_strcmp(dir, "/"))
		dir = ft_strcleanjoin(dir, "/");
	if (ft_strcmp(newdir, ".") && ft_strcmp(newdir, ".."))
		dir = ft_strcleanjoin(dir, newdir);
	return (dir);
}

t_file *ft_getls(char *dir)
{
	DIR* rep;
	struct dirent *readfile;
	t_file *file;
	t_file	*cpy;

	cpy = NULL;
	if (!(rep = opendir(dir)))
		return (process_error(dir, (int)errno));
	while ((readfile = readdir(rep)))
	{
		if (cpy)
		{
			cpy->next = get_info(dir, readfile->d_name);
			cpy = cpy->next;
		}
		else
		{
			cpy = get_info(dir, readfile->d_name);
			file = cpy;
		}
	}
	closedir(rep);
	ft_mergesort(&file);
	return (file);
}

int	process(t_ls *data)
{
	int	i;

	i = -1;
	if (!(data->files = malloc(sizeof(t_file) * data->nb_dir)))
		return (0);
	while (++i < data->nb_dir)
		data->files[i] = ft_getls(data->dir[i]);
	return(1);
}
