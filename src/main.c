/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:15:29 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/05 09:49:51 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_getdir(int argc, char **argv, int i, t_ls *data)
{
	int y;

	y = 0;
	if (i == argc)
	{
		if (!(data->dir = (char**)malloc(sizeof(char*) * 2)))
			return (0);
		data->dir[0] = ft_strdup(".");
		data->dir[1] = NULL;
		data->nb_dir = 1;
		return (1);
	}
	if (!(data->dir = (char**)malloc(sizeof(char *) *
					(size_t)(argc - i + 1))))
		return (0);
	while (i < argc)
	{
		data->dir[y++] = ft_strdup(argv[i]);
		i++;
	}
	data->dir[y] = 0;
	data->nb_dir = y;
	return (1);
}

int		ft_getoption(char c)
{
	int i;

	i = -1;
	while (++i < (int)ft_strlen(FG_OPTS))
		if (FG_OPTS[i] == c)
			return (1 << i);
	return (0);
}

int		ft_getargs(int argc, char **argv, t_ls *data)
{
	int i;
	int j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		if (argv[i][0] && argv[i][0] == '-')
		{
			if (!ft_strcmp(argv[i], "--"))
			{
				i++;
				break ;
			}
			while (argv[i][++j])
			{
				if (!(data->flags = ft_getoption(argv[i][j])))
					return ((int)(data->error = argv[i][j]));
				data->opts |= data->flags;
			}
		}
		else
			break ;
	}
	return (!(ft_getdir(argc, argv, i, data)) ? 0 : 1);
}

void	ft_initializels(t_ls *data)
{
	data->opts = 0;
	data->error = 0;
	data->dir = NULL;
	data->files = NULL;
	data->alone_files = NULL;
	data->flags = 0;
	data->nb_dir = 0;
}

int		main(int argc, char **argv)
{
	t_ls	*data;
	int		ret;

	if (!(data = malloc(sizeof(t_ls))))
		return (0);
	ft_initializels(data);
	if (!(ret = ft_getargs(argc, argv, data)))
	{
		free(data);
		exit(EXIT_FAILURE);
	}
	if (data->error)
	{
		write(2, "ft_ls: illegal option -- ", 25);
		ft_putchar_fd(data->error, 2);
		ft_putchar_fd('\n', 2);
		write(2, "usage: ft_ls [-", 15);
		ft_putstr_fd(FG_OPTS, 2);
		write(2, "] [file ...]\n", 13);
		exit(EXIT_FAILURE);
	}
	process(data);
	display(data);
	free_ls(&data);
	exit(EXIT_SUCCESS);
}
