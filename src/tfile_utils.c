/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tfile_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 11:49:37 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/03 12:04:42 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file *t_file_findlast(t_file *file)
{
	while (file && file->next)
		file = file->next;
	return (file);
}

int		mergefile(t_file **list, t_file *merge)
{
	if (!merge)
		return (0);
	if (!list || !*list)
	{
		*list = merge;
		return (0);
	}
	t_file_findlast(*list)->next = merge;
	return (1);
}
