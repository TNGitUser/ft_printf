/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:02:23 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/13 18:27:59 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "libft.h"

typedef struct		s_arg
{
	int				type;
	char			*str;
	void			*data;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_carg
{
	t_list			**list;
	int				cn;
}					t_carg;

/*
** ft_printf.c
*/
int					ft_printf(const char *str, ...);

t_arg				*ft_readarg(char *str, va_list ap);

#endif
