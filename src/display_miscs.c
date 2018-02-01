/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_miscs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:37:22 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/01 13:26:25 by elebouch         ###   ########.fr       */
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
	if (data->fg_bg)
		ft_putstr(get_color(file));
	if (i == -1)
		ft_putstr(file->path);
	else
		ft_putstr(file->file_name);
	if (data->fg_bg)
		ft_putstr(RESET);
	if (!(S_ISLNK(file->stat.st_mode) && data->fg_l))
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
	ft_putstr(link_name);
	ft_putchar('\n');
}

void	print_majmin(t_file *file, t_size size)
{
	putpadnbr((size_t)major(file->stat.st_rdev), size.maj + 1, 0);
	ft_putchar(',');
	putpadnbr((size_t)minor(file->stat.st_rdev), size.min + 1, 0);
}
