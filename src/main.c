/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:15:29 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/26 13:21:35 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_getdir(int argc, char **argv, int i, t_ls *data)
{
	int y;

	y = 0;
	if (i == argc)
	{
		if (!(data->dir = (char**)malloc(sizeof(char *)	* 2)))
			return (0);
		data->dir[0] = ft_strdup(".");
		data->dir[1] = NULL;
		data->nb_dir = 1;
		return (1);
	}
	if (!(data->dir = (char**)malloc(sizeof(char *) * (argc - i + 1))))
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

int	ft_getoption(char *str, t_ls *data)
{
	if (*str)
		str++;
	while (*str)
	{
		if (*str == 'l')
			data->fg_l = 1;
		else if (*str == 'a')
			data->fg_a = 1;
		else if (*str == 'R')
			data->fg_br = 1;
		else if (*str == 'r')
			data->fg_sr = 1;
		else if (*str == 't')
			data->fg_t = 1;
		else 
			break;
		str++;
	}
	if (!data->fg_l && !data->fg_sr && !data->fg_br && !data->fg_t &&
			!data->fg_a)
	{
		ft_printf("ft_ls: illegal option -- %s\n",str);
		return (0);
	}
	return (1);
}

int		ft_getargs(int argc, char **argv, t_ls *data)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] && argv[i][0] == '-')
		{
			if (!(ft_getoption(argv[i], data)))
				return (-1);
		}
		else
			break ;
	}
	if (!(ft_getdir(argc, argv, i, data)))
		return (0);
	return (1);
}
void	ft_initializels(t_ls *data)
{
	data->fg_l = 0;
	data->fg_sr = 0;
	data->fg_br = 0;
	data->fg_a = 0;
	data->fg_t = 0;
	data->dir = NULL;
	data->files = NULL;
	data->nb_dir = 0;
}
int		main(int argc, char **argv)
{
	t_ls		*data;
	int ret;

	if (!(data = malloc(sizeof(t_ls))))
		return (0);
	ft_initializels(data);
	if (!(ret = ft_getargs(argc, argv, data)))
	{
		free(data);
		return (0);
	}
	else if (ret == -1)
	{
		free(data);
		printf("usage: ft_ls [-aRrtl] [file ...]\n");
		return (0);
	}
	process(data);	
	display(data);
	free_ls(&data);
}
