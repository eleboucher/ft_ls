/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_miscs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:37:22 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/04 10:18:52 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_color(t_file *file)
{
	mode_t mode;

	mode = file->stat.st_mode;
	if (S_ISFIFO(mode))
		return (YEL);
	else if (S_ISCHR(mode))
		return (YEL);
	else if (S_ISBLK(mode))
		return (BLU);
	else if (S_ISLNK(mode))
		return (MAG);
	else if (S_ISSOCK(mode))
		return (GRN);
	else if (S_ISDIR(mode))
		return (BOLCYN);
	return (DFT);
}

void	print_acl(t_file *file)
{
	acl_t	t;

	t = NULL;
	if (listxattr(file->path, NULL, 0, XATTR_NOFOLLOW))
	{
		ft_putchar('@');
		return ;
	}
	if ((t = acl_get_file(file->path, ACL_TYPE_EXTENDED)))
	{
		ft_putchar('+');
		acl_free((void*)t);
	}
	else
		ft_putchar(' ');
}

void	display_file_name(t_file *file, t_ls *data, int i)
{
	int color;

	color = (data->opts & FG_BG);
	if (i == -1 && !(file->path[0] == '.' && file->path[0] == '/'))
		ft_printf("%s%s%s", (color) ? get_color(file) : "",
				file->path, (color) ? RESET: "");
	else
		ft_printf("%s%s%s", ((color) ? get_color(file) : ""),
				file->file_name, ((color) ? RESET: ""));
	if (!(S_ISLNK(file->stat.st_mode) && (data->opts & FG_L)))
		ft_putchar('\n');
	else
		display_link(file);
}

void	display_link(t_file *file)
{
	char link_name[1024];

	ft_putstr(" -> ");
	ft_bzero(&link_name, 1024);
	readlink(file->path, link_name, 1024);
	ft_printf("%s\n", link_name);
}

void	print_majmin(t_file *file, t_size size)
{
	putpadnbr((size_t)major(file->stat.st_rdev), size.maj + 1, 0);
	ft_putchar(',');
	putpadnbr((size_t)minor(file->stat.st_rdev), size.min + 1, 0);
}
