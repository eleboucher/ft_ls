/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:04:13 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/10 14:44:08 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct	s_prtf
{
	int			precision;
	int			width;
	int			modifier;
	char		format;
	int			fg_hashtag;
	int			fg_zero;
	int			fg_minus;
	int			fg_space;
	int			fg_plus;
	int			neg;
}				t_prtf;

enum			e_modifier {
	none,
	md_h,
	md_db_h,
	md_l,
	md_db_l,
	md_j,
	md_z
};

char			*ft_parse_args(t_prtf *data, char **fmt);
int				ft_parse_intarg(char **fmt);
int				ft_parse_mod(char **fmt);
int				ft_proc_arg(char **fmt, va_list ap);
void			ft_getflags(char **fmt, t_prtf *data);
int				ft_print(const char *format, va_list ap);
int				ft_printf(const char *format, ...);
int				ft_print_args(t_prtf *data, va_list ap);
int				ft_printstr(char *s, t_prtf *data);
int				ft_formatstr(t_prtf *data, va_list ap);
int				ft_formatchr(t_prtf *data, va_list ap);
int				ft_formatint(t_prtf *data, va_list ap);
int				ft_formatuint(t_prtf *data, va_list ap);
int				ft_formatlong(t_prtf *data, va_list ap);
int				ft_printstr(char *str, t_prtf *data);
char			*ft_precision(char *s, t_prtf *data);
int				ft_width(size_t len, t_prtf *data, char *str);
int				ft_getwidthsize(int len, t_prtf *data, char *str);
int				ft_prefix(char *str, t_prtf *data);
void			ft_initialize(t_prtf *data);
int				ft_formatbigc(t_prtf *data, va_list ap);
int				ft_formatbigs(t_prtf *data, va_list ap);
int				ft_printpointer(t_prtf *data, va_list ap);
#endif
