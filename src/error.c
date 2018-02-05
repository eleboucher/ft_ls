/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:39:07 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/05 09:45:40 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*perm(char *dir, char *file_name)
{
	char	*str;
	t_file	*file;

	str = ft_strdup("ft_ls: ");
	str = ft_strcleanjoin(str, file_name);
	str = ft_strcleanjoin(str, ": Permission denied\n");
	if (!(file = malloc(sizeof(t_file))))
		return (NULL);
	file->error = 1;
	file->dir = ft_strdup(dir);
	file->path = ft_strdup(dir);
	ft_strcpy(file->file_name, str);
	free(str);
	free(file_name);
	return (file);
}

static void		enoent(char *f)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(f, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

static char		*get_dir(char **split, char *dir, int size)
{
	char	*d;
	int		i;

	if (dir[0] == '/')
	{
		d = ft_strdup("/");
		d = ft_strcleanjoin(d, split[0]);
	}
	else
		d = ft_strdup(split[0]);
	if (size > 2)
		d = ft_strcleanjoin(d, "/");
	i = 0;
	while (++i < size - 1)
	{
		d = ft_strcleanjoin(d, split[i]);
		if (i < size - 2)
			d = ft_strcleanjoin(d, "/");
	}
	return (d);
}

static t_file	*enotdir(t_ls *data, char *f, char *d, int i)
{
	(i == 1) ? mergefile(&data->alone_files, get_info(".", f)) :
		mergefile(&data->alone_files, get_info(d, f));
	free(d);
	return (NULL);
}

t_file			*process_error(char *dir, int error, t_ls *data)
{
	char	**file_name;
	char	*f;
	char	*d;
	int		i;

	file_name = (dir && *dir) ? ft_strsplit(dir, '/') :
		ft_strsplit("fts_open \n", '\n');
	i = 0;
	while (file_name[i])
		++i;
	f = ft_strdup(file_name[i - 1]);
	d = get_dir(file_name, dir, i);
	freearr(&file_name);
	if (error == ENOTDIR)
		return (enotdir(data, f, d, i));
	else if (error == EACCES)
	{
		free(d);
		return (perm(dir, f));
	}
	else if (error == ENOENT)
		enoent(f);
	free(d);
	free(f);
	return (0);
}
