/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 21:13:30 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/13 21:15:49 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cflt(t_arg *la, va_list ap)
{
	char		*out;
	long double	nu;

	out = NULL;
	nu = va_arg(ap, long double);
	if (!(out = ft_coct_aux(nu)))
		exit(1);
	la->data = (void *)out;
}
