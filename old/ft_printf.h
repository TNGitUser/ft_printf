/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:02:23 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/12 13:07:53 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/*
** *pr		: Precision flag
** *fs		: Field size
** *prefix	: informations regarding the padding (with 0 | blank | 0x | 0X)
**				0  is blank
**				-1 is zero
**				1  is 0x or 0X is cflag is X
** *pads	: informations regarding the padding size ( + left | - right)
** *sign	: informations regarding the display of the sign
**				( 1 is sign at all time, 0 is space at the place of the '+'
**				-1 is do not display sign if positive).
**				The flag '+' override ' '.
*/
typedef struct	s_ext
{
	int			*pr;
	int			*fs;
	int			*prefix;
	int			*pads;
	int			*sign;
}				t_ext;
/*
** *pos		: Array of the conversion flag indexes in the original string
** cvn		: Total of conversion (used to iterate throught the struct array)
** **df		: Array of the formated data corresponding to the convertion
*/
typedef struct	s_pargs
{
	int			*pos;
	size_t		cvn;
	char		**df;
	t_ext		*ext;
	char		*exitus;
}				t_pargs;

/*
** ft_format.c
*/
char			*ft_format(t_pargs *args, const char *str);

/*
** ft_printf.c
*/
int				ft_printf(const char *str, ...);

/*
** ft_hex.c
*/
char			*ft_chex(void *v_char);

/*
** ft_stdconv.c
*/
void			ft_ci(t_pargs *args, int n, int c);

/*
** ft_stdconv.c
*/
void			ft_cchar(t_pargs *args, int v_char, int c);
void			ft_cstr(t_pargs *args, char *str, int c);
void			ft_cptr(t_pargs *args, void *str, int c);
/*
** ft_stdconv.c
*/
void			ft_cchar(t_pargs *args, int v_char, int c);
void			ft_cstr(t_pargs *args, char *str, int c);
void			ft_cptr(t_pargs *args, void *str, int c);

/*
** ft_ext.c
*/
void			ft_init_ext(t_pargs *args);
void			ft_free_ext(t_ext *ext);
void			ft_set_ext(t_pargs *args, int c, const char *str, int len);

/*
** ft_mconv.c
*/
void			ft_ci(t_pargs *args, int n, int c);

/*
** ft_args.c
*/
int				ft_is_cflag(char c);
size_t			ft_count(const char *str);
t_pargs			*ft_args(const char *str);

/*
** aux
*/
char			*ft_strdup(char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsub(char const *src, unsigned int start, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_itoa(long n);
int				ft_atoi(const char *str, int *i);
size_t			ft_strlen(const char *str);
void			ft_memdel(void **ptr);
void			ft_bzero(void *ptr, size_t n);
void			*ft_memalloc(size_t n);
void			ft_set_fs(t_pargs *args, int c, int n);
#endif
