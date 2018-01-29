/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 09:55:56 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/29 16:29:17 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	maxsize_guid(t_file *f, t_size *s, int fg_a)
{
	while (f)
	{
		if (!(!fg_a && f->file_name[0] == '.'))
		{
			if (getpwuid(f->stat.st_uid))
			{
				if (ft_strlen(getpwuid(f->stat.st_uid)->pw_name) > s->uid)
					s->uid = ft_strlen(getpwuid(f->stat.st_uid)->pw_name);
			}
			else
				s->uid = (countdigit(f->stat.st_uid, 0) > s->uid) ?
					countdigit(f->stat.st_uid, 0) : s->uid;
			if (getgrgid(f->stat.st_gid))
			{
				if (ft_strlen(getgrgid(f->stat.st_gid)->gr_name) > s->gid)
					s->gid = ft_strlen(getgrgid(f->stat.st_gid)->gr_name);
			}
			else
				s->gid = (countdigit(f->stat.st_gid, 0) > s->gid) ?
					countdigit(f->stat.st_gid, 0) : s->gid;
		}
		f = f->next;
	}
}

void	max_nlinknsize(t_file *f, t_size *s, int fg_a)
{
	while (f)
	{
		if (!(!fg_a && f->file_name[0] == '.'))
		{
			s->nlink = (countdigit(f->stat.st_nlink, 0) > s->nlink) ?
				countdigit(f->stat.st_nlink, 0) : s->nlink;
			if (S_ISCHR(f->stat.st_mode) || S_ISBLK(f->stat.st_mode))
			{
				if ((countdigit(major(f->stat.st_rdev), 0) +
						countdigit(minor(f->stat.st_rdev), 0) + 4) > s->size)
				{
					s->size = countdigit(major(f->stat.st_rdev), 0) + 
						countdigit(minor(f->stat.st_rdev), 0) + 4;
					s->maj = countdigit(major(f->stat.st_rdev), 0);
					s->min = countdigit(minor(f->stat.st_rdev), 0);
				}
			}
			else
				s->size = (countdigit(f->stat.st_size, 0) > s->size) ?
					countdigit(f->stat.st_size, 0) : s->size;
		}
		f = f->next;
	}
}

size_t	countdigit(long n, int i)
{
	if (n == 0 && i == 0)
		return (1);
	return ((n > 0) ? countdigit(n / 10, i + 1) : i);
}

void	init_size(t_size *size)
{
	size->nlink = 0;
	size->size = 0;
	size->uid = 0;
	size->gid = 0;
}
