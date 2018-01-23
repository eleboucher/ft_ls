/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:17:34 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/23 23:55:19 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "libft.h"

typedef struct		s_file 
{
#ifdef _DARWIN_FEATURE_64_BIT_INODE
	char			file_name[1024];
#else
	char			file_name[256];
#endif
	char			*path;
	int				isdir;
	struct stat		stat;
	struct s_file	*inside;
	struct s_file	*next;
}					t_file;

typedef struct		s_ls
{
	int				fg_l;
	int				fg_a;
	int				fg_br;
	int				fg_sr;
	int				fg_t;
	int				nb_dir;
	char			**dir;
	t_file			**files;
}					t_ls;
void	display(t_ls *data);
int		process(t_ls *data);
t_file 	*get_info(char *dir, char *d_name);
char *joindir(char *dir,char *newdir);
t_file *ft_getls(char *dir);
#endif
