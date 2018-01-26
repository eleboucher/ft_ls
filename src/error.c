/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:39:07 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/26 14:01:02 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
		printf("ls: %s: Permission denied\n", file_name[i - 1]);
	return(NULL);
}
