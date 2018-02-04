/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 09:47:35 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/04 10:34:01 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_type(t_file *file, int fg_pls)
{
	char	c;
	mode_t	mode;

	mode = file->stat.st_mode;
	if (S_ISFIFO(mode))
		c = 'p';
	else if (S_ISCHR(mode))
		c = 'c';
	else if (S_ISDIR(mode))
		c = 'd';
	else if (S_ISBLK(mode))
		c = 'b';
	else if (S_ISLNK(mode))
		c = 'l';
	else if (S_ISSOCK(mode))
		c = 's';
	else
		c = '-';
	ft_putchar(c);
	print_right(file, fg_pls);
}

void	print_right(t_file *file, int fg_pls)
{
	char	ret[9];
	mode_t	mode;

	mode = file->stat.st_mode;
	ret[0] = (mode & S_IRUSR) ? 'r' : '-';
	ret[1] = (mode & S_IWUSR) ? 'w' : '-';
	ret[2] = (mode & S_IXUSR) ? 'x' : '-';
	ret[3] = (mode & S_IRGRP) ? 'r' : '-';
	ret[4] = (mode & S_IWGRP) ? 'w' : '-';
	ret[5] = (mode & S_IXGRP) ? 'x' : '-';
	ret[6] = (mode & S_IROTH) ? 'r' : '-';
	ret[7] = (mode & S_IWOTH) ? 'w' : '-';
	ret[8] = (mode & S_IXOTH) ? 'x' : '-';
	if (mode & S_ISUID)
		ret[2] = (ret[2] == '-') ? 'S' : 's';
	if (mode & S_ISGID)
		ret[5] = (ret[5] == '-') ? 'S': 's';
	if (mode & S_ISVTX)
		ret[8] = (ret[8] == '-') ? 'T' : 't';
	write(1, ret, 9);
	if (fg_pls)
		print_acl(file);
	else
		ft_putchar(' ');
}

void	print_total(t_file *file, int fg_a)
{
	int total;
	int i;

	total = 0;
	i = 0;
	while (file)
	{
		if (!(!fg_a && file->file_name[0] == '.'))
		{
			total += (int)file->stat.st_blocks;
			i++;
		}
		file = file->next;
	}
	if (i)
		ft_printf("total %d\n", total);
}

void	print_guid(t_file *file, t_size size)
{
	if (getpwuid(file->stat.st_uid))
		putpadstr(getpwuid(file->stat.st_uid)->pw_name, size.uid, 1);
	else
		putpadnbr(file->stat.st_uid, size.uid + 1, 1);
	if (getgrgid(file->stat.st_gid))
		putpadstr(getgrgid(file->stat.st_gid)->gr_name, size.gid, 1);
	else
		putpadnbr(file->stat.st_gid, size.gid + 1, 1);
}

void	print_date(t_file *file)
{
	time_t	now;
	time_t	mtime;
	time_t	diff;
	char	*str;

	now = time(NULL);
	mtime = file->stat.st_mtime;
	str = ctime(&mtime);
	diff = now - mtime;
	ft_putchar(' ');
	ft_putnstr(&(str[4]), 6);
	ft_putchar(' ');
	if (ft_labs(diff) > (3600 * 24 * 30.5 * 6))
	{
		ft_putchar(' ');
		ft_putnstr(&(str[20]), 4);
	}
	else
		ft_putnstr(&(str[11]), 5);
	ft_putchar(' ');
}
