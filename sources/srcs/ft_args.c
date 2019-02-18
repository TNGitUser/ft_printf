/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:29:15 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/18 10:31:51 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_getctype(char *str, int i)
{
	if (str[i] == 'c')
		return (0);
	else if (str[i] == 's')
		return (1);
	else if (str[i] == 'p')
		return (2);
	else if (str[i] == 'i' || str[i] == 'd')
		return (3);
	else if (str[i] == 'f')
		return (4);
	else if (str[i] == 'o')
		return (5);
	else if (str[i] == 'u')
		return (6);
	else if (str[i] == 'x' || str[i] == 'X')
		return (str[i] == 'x' ? 7 : 8);
	else if (str[i] == '%')
		return (9);
	return (-1);
}

static void	ft_idontknow()
{

}

int		ft_iseflag(char *str, int i)
{
	int		c;
	char	m;

	c = 0;
	m = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'l' || str[i] == 'h' || str[i] == 'L')
		{
			if (m != 0 && m != str[i])
				break ;//exit(1);
			m = str[i];
			if (str[i] == 'l')
				c += 10;
			else
				c += str[i] == 'h' ? 30 : 50;
		}
		else
			break ;
		--i;
	}
	return (c);
}

int		ft_checknflag(int mod, int type)
{
	if (mod == 0)
		return (1);
	if (type == 3)
	{
		if (mod == 10 || mod == 20 || mod == 30 || mod == 60)
			return (1);
		else
			return (0);
	}
	else if (type >= 5 && type <= 8)
	{
		if (mod == 10 || mod == 20 || mod == 30 || mod == 60)
			return (1);
		else
			return (0);
	}
	else if (type == 4)
		return (mod == 10 || mod == 50);
	return (1);
}

void	ft_getcdata(int type, t_arg *la, va_list ap)
{
	if (type == 0)
		ft_cchr(la, ap);
	if (type == 1)
		ft_cstr(la, ap);
	if (type == 2)
		ft_cptr(la, ap);
	if (type == 3)
		ft_cint(la, ap);
	if (type == 4)
		ft_cflt(la, ap);
	if (type == 5)
		ft_coct(la, ap);
	if (type == 6)
		ft_cund(la, ap);
	if (type == 7 || type == 8)
		ft_cunh(la, ap, type - 7);
}

t_arg	*ft_readarg(char *str, va_list ap)
{
	t_arg	*cv;
	int		type;
	int		mod;
	size_t	len;

	if (!(cv = malloc(sizeof(t_arg))))
		return (NULL);
	len = ft_strlen(str);
	type = ft_getctype(str, len - 1);
	mod = ft_iseflag(str, len - 2);
	cv->next = NULL;
	cv->str = str;
	cv->type = type;
	cv->data = NULL;
	ft_getcdata(type, cv, ap);
	ft_init_ef(cv, mod);
	if (!ft_checknflag(mod, type))
	{
		ft_memdel((void **)&str);
		ft_memdel((void **)&cv);
		return (NULL);
	}
	return (cv);
}
