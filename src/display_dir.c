/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 13:02:27 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/02 16:04:44 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_dir(t_file *file)
{
	char	*tmp;
	int		i;

	while (file && ft_strcmp(file->file_name, "."))
		file = file->next;
	i = ft_strlen(file->path);
	while (--i > 0)
		if (file->path[i] == '/')
			break ;
	tmp = ft_strsub(file->path, 0, i);
	printf("%s:\n", tmp);
	free(tmp);
}
