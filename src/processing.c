/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:02:51 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/24 11:39:44 by elebouch         ###   ########.fr       */
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
	lstat(dir, &file->stat);
	file->isdir = 0;
	file->next = NULL;
	return (file);
}

char *joindir(char *dir,char *newdir)
{
	dir = ft_strjoin(dir, "/");
	dir = ft_strjoin(dir, newdir);
	return (dir);
}

t_file *ft_getls(char *dir)
{
	DIR* rep;
	struct dirent *readfile;
	t_file *file;
	t_file	*cpy;


	cpy = NULL;
	if (!(rep = opendir(dir)) && errno == ENOTDIR)
		return (NULL);
	if (!rep)
		return (NULL);
	printf("PATH ------> %s\n", dir);
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
	return (file);
}

int	process(t_ls *data)
{
	int	i;

	i = -1;
	if (!(data->files = malloc(sizeof(t_file) * data->nb_dir)))
		return (0);
	while (++i < data->nb_dir)
	{
		data->files[i] = ft_getls(data->dir[i]);
	}
	return(1);
}
