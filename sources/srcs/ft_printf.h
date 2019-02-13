/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:02:23 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/13 14:32:21 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "libft.h"

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

typedef struct	s_carg
{
	t_list		**list;
	int			cn;
}				t_carg;

/*
** ft_printf.c
*/
int				ft_printf(const char *str, ...);

void			ft_readarg(char *str, va_list ap);

#endif
