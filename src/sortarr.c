/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortarr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 07:15:49 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/05 11:41:05 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file			*get_folder(t_file *file)
{
	while (file && !file->error && ft_strcmp(file->file_name, "."))
		file = file->next;
	return (file);
}

static int		pushnullatend(t_file ***arr, int n)
{
	int		i;
	int		count;
	int		nbdir;
	t_file	**files;

	count = 0;
	nbdir = 0;
	i = -1;
	files = *arr;
	while (++i <= n)
		if (files[i])
		{
			files[count++] = files[i];
			nbdir++;
		}
	while (count <= n)
		files[count++] = NULL;
	return (nbdir);
}

int				sortdirarr(t_file ***arr, int n, int (*f)(t_file *a, t_file *b))
{
	t_file	**files;
	int		i;
	t_file	*key;
	t_file	*cpy;
	int		j;

	if (!arr)
		return (0);
	n = pushnullatend(arr, n);
	files = *arr;
	i = 0;
	while (++i < n)
	{
		cpy = files[i];
		key = get_folder(files[i]);
		j = i - 1;
		while (j >= 0 && (*f)(get_folder(files[j]), key) > 0)
		{
			files[j + 1] = files[j];
			j = j - 1;
		}
		files[j + 1] = cpy;
	}
	return (n);
}

void			reverse_arr(t_file ***arr, int size)
{
	int		i;
	int		j;
	t_file	*tmp;
	t_file	**files;

	i = size - 1;
	j = 0;
	files = *arr;
	while (i > j)
	{
		tmp = files[i];
		files[i] = files[j];
		files[j] = tmp;
		i--;
		j++;
	}
}
