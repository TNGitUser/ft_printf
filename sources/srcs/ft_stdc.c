/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:29:18 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/22 12:02:52 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cchr(t_arg *la, va_list ap)
{
	char	ch;
	char	*dstr;

	if (!(dstr = malloc(sizeof(char) * 2)))
		dstr = ft_strdup("(null)");
	else
	{
		ch = va_arg(ap, int);
		dstr[0] = ch;
		dstr[1] = '\0';
	}
	la->data = (void *)dstr;
}

void	ft_cptr(t_arg *la, va_list ap)
{
	char	*out;
	char	*tmp;
	void	*ptr;

	ptr = va_arg(ap, void *);
	if (!(out = ft_chex(ptr, 0, 0)))
		out = ft_strdup("(null)");
	else
	{
		tmp = out;
		out = ft_strjoin("0x", out);
		ft_memdel((void **)&tmp);
	}
	la->data = (void *)out;
}

void	ft_cint(t_arg *la, va_list ap)
{
	char		*out;
	long long	nu;

	if (la->ef->lmod == 10)
		nu = va_arg(ap, long);
	else if (la->ef->lmod == 20)
		nu = va_arg(ap, long long);
	else
		nu = va_arg(ap, int);
	if (!(out = ft_ltoa(nu)))
		out = ft_strdup("(null)");
	la->data = (void *)out;
}

void	ft_cstr(t_arg *la, va_list ap)
{
	char *str;

	str = va_arg(ap, char *);
	if (!str)
		exit(1);
	la->data = (void *)str;
}

void	ft_coct(t_arg *la, va_list ap)
{
	char		*out;
	long long	nu;

	out = NULL;
	nu = va_arg(ap, long long);
	if (!(out = ft_coct_aux(nu)))
		exit(1);
	la->data = (void *)out;
}
