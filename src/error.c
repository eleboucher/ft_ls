/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:39:07 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/31 13:43:47 by elebouch         ###   ########.fr       */
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
	file->path = ft_strdup(dir);
	ft_strcpy(file->file_name, str);
	free(str);
	free(file_name);
	return (file);
}
static void		freearr(char ***arr)
{
	char **file_name;
	int	 i;

	file_name = *arr;
	i = -1;
	while (file_name[++i])
		free(file_name[i]);
	free(file_name);
}

t_file			*process_error(char *dir, int error)
{
	char	**file_name;
	char	*f;
	int		i;

	file_name = (dir && *dir) ? ft_strsplit(dir, '/') :
               ft_strsplit("fts_open \n", '\n');
	i = 0;
	while (file_name[i])
		++i;
	f = ft_strdup(file_name[i - 1]);
	freearr(&file_name);
	if (error == ENOTDIR)
	{
		if (i == 1)
			return (get_info(".", f));
		else
			return (get_info(dir, f));
	}
	if (error == EACCES)
		return (perm(dir, f));
	if (error == ENOENT)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(f, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	free(f);
	return (NULL);
}
