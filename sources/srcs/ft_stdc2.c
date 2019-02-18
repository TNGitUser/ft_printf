/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 21:13:30 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/18 12:48:34 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_cflt(t_arg *la, va_list ap)
{
	char		*out;
	double		nu;

	out = NULL;
	nu = va_arg(ap, double);
	la->data = (void *)out;
}

void		ft_cund(t_arg *la, va_list ap)
{
	char		*out;
	long double	nu;

	out = NULL;
	nu = va_arg(ap, long long);
	la->data = (void *)out;
}

static void	ft_upcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] -= 32;
		++i;
	}
}

void		ft_cunh(t_arg *la, va_list ap, int type)
{
	char		*out;
	long double	nu;

	out = NULL;
	nu = va_arg(ap, long long);
	if (!(out = ft_chex(NULL, nu, 1)))
		exit(1);
	if (type == 1)
		ft_upcase(out);
	la->data = (void *)out;
}
