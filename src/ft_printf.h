/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:02:25 by lucmarti          #+#    #+#             */
/*   Updated: 2019/04/29 16:02:14 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "../libft/libft.h"

typedef struct	s_trail
{
	va_list		ap;
	char		*ftext;
	int			printed;
}				t_trail;

/*
**	0	| 1		| 2	| 3 | 4 | 5 | 6 | 7 | 8
**	alt	  zero	  +   -  ' '
*/
typedef struct	s_stat
{
	short		flags;
	int			alt;
	int			adj;
	int			form;
	int			zero;
	int			fs;
	int			pr;
	char		fmt;
	char		*mod;

}				t_stat;

/*
**	hex.c
*/
char			*ft_chex(void *ptr, long long n, int t);

/*
**	init.c
*/
t_trail			*trail_init(char *text);
void			trail_free(t_trail *core);

/*
**	bool.c
*/
int				is_type(char c);

/*
**	peacemaker.c
*/
void			set_priorities(t_stat *arg);

/*
**	parser.c
*/
int				parse_arg(char *text);

/*
**	ft_printf.c
*/
int				ft_printf(char *text, ...);

/*
**	error.c
*/
void			err_die(char *msg);

#endif
