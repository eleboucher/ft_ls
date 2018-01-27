/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rights.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 11:27:47 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/27 12:01:13 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char print_type(mode_t mode)
{
	if (S_ISFIFO(mode))
		return ('p');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISSOCK(mode))
		return ('s');
	return ('-');
}

char *print_right(mode_t mode)
{
	char *ret;

	if (!(ret = (char*)malloc(sizeof(char) * 10)))
		return (NULL);
	ret[0] = (mode & S_IRUSR) ? 'r' : '-';
	ret[1] = (mode & S_IWUSR) ? 'w' : '-';
	ret[2] = (mode & S_IXUSR) ? 'x' : '-';
	ret[3] = (mode & S_IRGRP) ? 'r' : '-';
	ret[4] = (mode & S_IWGRP) ?	'w' : '-';
	ret[5] = (mode & S_IXGRP) ? 'x' : '-';
	ret[6] = (mode & S_IROTH) ? 'r' : '-';
	ret[7] = (mode & S_IWOTH) ? 'w' : '-';
	ret[8] = (mode & S_IXOTH) ? 'x' : '-';
	ret[9] = 0;
	return (ret);
}
