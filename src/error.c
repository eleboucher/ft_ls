/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:39:07 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/29 16:59:57 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file *process_error(char *dir, int error)
{
	char **file_name;
	char *str;
	t_file *file;
	int i;

	file_name = ft_strsplit(dir, '/');
	i = -1;
	file = NULL;
	str = NULL;
	while (file_name[++i]);
	if (error == ENOTDIR)
		return (get_info(dir, file_name[i - 1]));
	if (error == EACCES)
	{
		str = ft_strdup("ft_ls: "); 
		str = ft_strcleanjoin(str, file_name[i - 1]);
		str = ft_strcleanjoin(str, ": Permission denied\n");
		if (!(file = malloc(sizeof(t_file))))
			return (NULL);
		file->error = 1;
		file->path = ft_strdup(dir);
		ft_strcpy(file->file_name, str);
		free(str);
	}
	return(file);
}
