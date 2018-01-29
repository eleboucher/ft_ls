/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:39:07 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/29 18:26:44 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file *perm(char *dir, char *file_name)
{
	char *str;
	t_file *file;

	str = ft_strdup("ft_ls: "); 
	str = ft_strcleanjoin(str, file_name);
	str = ft_strcleanjoin(str, ": Permission denied\n");
	if (!(file = malloc(sizeof(t_file))))
		return (NULL);
	file->error = 1;
	file->path = ft_strdup(dir);
	ft_strcpy(file->file_name, str);
	free(str);
	return(file);
}

t_file *process_error(char *dir, int error)
{
	char **file_name;
	int i;

	file_name = ft_strsplit(dir, '/');
	i = -1;
	while (file_name[++i]);
	if (error == ENOTDIR)
		return (get_info(dir, file_name[i - 1]));
	if (error == EACCES)
		return (perm(dir, file_name[i - 1]));
	if (error == ENOENT)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(file_name[i - 1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	return(NULL);
}
