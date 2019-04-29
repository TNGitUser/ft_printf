/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peacemaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:28:18 by lucmarti          #+#    #+#             */
/*   Updated: 2019/04/29 15:37:53 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_integer(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

void			set_priorities(t_stat *arg)
{
	if (arg->pr != 0 && is_integer(arg->fmt) && arg->zero)
		arg->zero = 0;
	if (arg->zero && arg->adj)
		arg->zero = 0;
}
