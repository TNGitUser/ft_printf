/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:02:23 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/20 13:38:48 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "../libft/libft.h"

/*
** af		: Alternate form (#)
** zero		: is preceded by 0 if field size higher than conversion length
** pos...	: 0 nothing beside - if < 0 | 1 write + if > 0 | 2 write ' ' if > 0
** fsize	: minimal field size
** pr		: precision field
** lalign	: 0 right align, 1 left align, 2 both align
** lmod		: size modifier usign l/h/L flags
*/
typedef struct		s_eflag
{
	int				af;
	int				zero;
	int				positive;
	int				fsize;
	int				pr;
	int				lalign;
	int				lmod;
}					t_eflag;

typedef struct		s_arg
{
	int				type;
	char			*str;
	void			*data;
	struct s_arg	*next;
	t_eflag			*ef;
}					t_arg;

/*
** ft_printf.c
*/
int					ft_printf(const char *str, ...);

/*
** ft_args.c
*/
t_arg				*ft_readarg(char *str, va_list ap);

/*
** ft_stdc.c
*/
void				ft_cchr(t_arg *la, va_list ap);
void				ft_cptr(t_arg *la, va_list ap);
void				ft_cint(t_arg *la, va_list ap);
void				ft_cstr(t_arg *la, va_list ap);
void				ft_coct(t_arg *la, va_list ap);

/*
** ft_stdc2.c
*/
void				ft_cflt(t_arg *la, va_list ap);
void				ft_cund(t_arg *la, va_list ap);
void				ft_cunh(t_arg *la, va_list ap, int type);

/*
** ft_hex.c
*/
char				*ft_coct_aux(long long n);
char				*ft_chex(void *ptr, long long n, int t);

/*
** ft_eflag.c
*/
void				ft_init_ef(t_arg *arg, int mod);

void				ft_dis_ef(t_arg *arg);

/*
** ft_format.c
*/
char				*ft_format_str(const char *str, t_arg *args);

#endif
