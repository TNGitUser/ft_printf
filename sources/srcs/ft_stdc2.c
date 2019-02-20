/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 21:13:30 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/20 16:02:48 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_cflt(t_arg *la, va_list ap)
{
	char		*out;
	double		nu;

	out = NULL;
	if (la->ef->lmod == 50)
		nu = va_arg(ap, long double);
	else
		nu = va_arg(ap, double);
	printf("arg : %f\n", nu);
	if (!(out = ft_ftoa(nu, la->ef->pr)))
		out = ft_strdup("(null)");
	printf("out : [%s]\n", out);
	la->data = (void *)out;
}

void		ft_cund(t_arg *la, va_list ap)
{
	char			*out;
	unsigned long	nu;

	out = NULL;
	if (la->ef->lmod == 60)
		nu = va_arg(ap, int);
	else if (la->ef->lmod == 30)
		nu = va_arg(ap, int);
	else if (la->ef->lmod == 10)
		nu = va_arg(ap, unsigned long);
	else if (la->ef->lmod == 20)
		nu = va_arg(ap, unsigned long long);
	else
		nu = va_arg(ap, long long);
	if (!(out= ft_ltoa(nu)))
		out = ft_strdup("(null)");
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
	char				*out;
	long long	nu;

	out = NULL;
	if (la->ef->lmod == 60 || la->ef->lmod == 30)
		nu = va_arg(ap, int);
	else if (la->ef->lmod == 10)
		nu = va_arg(ap, unsigned long);
	else if (la->ef->lmod == 20)
		nu = va_arg(ap, unsigned long long);
	else
		nu = va_arg(ap, long long);
	if (!(out = ft_chex(NULL, nu, 1)))
		out = ft_strdup("(null)");
	if (type == 1)
		ft_upcase(out);
	la->data = (void *)out;
}
