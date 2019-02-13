/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:29:18 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/13 18:35:59 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cchar(t_arg *la, va_list ap)
{
	char	str;
	char	*dstr;

	str = va_arg(ap, char);
	if (!str)
		exit(1);
	la->data = (void *)str;
}

void	ft_cstr(t_arg *la, va_list ap)
{
	char *str;

	str = va_arg(ap, char *);
	if (!str)
		exit(1);
	la->data = (void *)str;
}
