/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:17:34 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/01 11:44:09 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include "libft.h"
# include "ft_printf.h"

# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[37m"
# define BOLCYN "\x1B[1;96m"
# define RESET "\x1B[0m"
# define DFT "\x1B[39m"

typedef struct		s_file
{
# ifdef _DARWIN_FEATURE_64_BIT_INODE

	char			file_name[1024];
# else

	char			file_name[256];
# endif

	char			*path;
	int				isdir;
	int				error;
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
	int				fg_bg;
	int				error;
	int				nb_dir;
	char			**dir;
	t_file			**files;
	t_file			*alone_files;
}					t_ls;

typedef struct		s_size
{
	size_t			uid;
	size_t			gid;
	size_t			size;
	size_t			nlink;
	size_t			maj;
	size_t			min;
}					t_size;

void				display(t_ls *data);
int					process(t_ls *data);
t_file				*get_info(char *dir, char *d_name);
char				*joindir(char *dir, char *newdir);
int					ft_getls(char *dir, t_file **to_merge, t_ls *data);
void				ft_mergesort(t_file **file, t_ls *data);
void				split(t_file *src, t_file **front, t_file **back);
t_file				*sorted(t_file *a, t_file *b,
		int (*f)(t_file *a, t_file *b));
void				free_ls(t_ls **ls);
int					process_error(char *dir, int error, t_ls *data);
void				print_type(t_file *file);
void				print_right(t_file *file);
void				print_total(t_file *file, int fg_a);
void				print_guid(t_file *file, t_size size);
void				maxsize_guid(t_file *file, t_size *size, int fg_a);
size_t				countdigit(long n, size_t i);
void				init_size(t_size *size);
void				max_nlinknsize(t_file *file, t_size *size, int fg_a);
void				putpadstr(char *str, size_t n, int fg_minus);
void				putpadnbr(size_t value, size_t n, int fg_minus);
void				print_date(t_file *file);
void				print_majmin(t_file *file, t_size size);
void				display_file_name(t_file *file, t_ls *data);
void				display_link(t_file *file);
void				reverse(t_file **file);
void				ft_quicksortfiles(t_file **files, int begin, int end);
int					ft_getdir(int argc, char **argv, int i, t_ls *data);
int					ft_getoption(char *str, t_ls *data);
int					ft_getargs(int argc, char **argv, t_ls *data);
void				ft_initializels(t_ls *data);
void				display_small(t_file *file, t_ls *data);
void				display_long(t_file *file, t_ls *data);
void				display_file(t_file *file, t_ls *data, int i);
void				print_acl(t_file *file);
char				*get_color(t_file *file);
void				free_file(t_file **files);
int					mergefile(t_file **list, t_file *merge);
#endif
