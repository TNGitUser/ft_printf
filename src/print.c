/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:43:19 by lucmarti          #+#    #+#             */
/*   Updated: 2019/04/30 12:10:40 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_trail(t_stat *arg, t_trail *core, int *i, int len)
{
	while (*i < arg->fs - (arg->pr != -1 ? arg->pr : len))
	{
		if (*i == 0 && arg->adj)
		{
			ft_putstrn(arg->str, (arg->pr != -1 ? arg->pr : len));
			core->printed += len;
		}
		if (arg->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		++(*i);
		++(core->printed);
	}
}

void	print_ptr(t_stat *arg, t_trail *core, int len)
{
	char	*out;
	int		i;

	out = ft_cptr(arg, core->ap);
	arg->str = out;
	len = ft_strlen(out);
	i = 0;
	arg->pr = arg->pr == 0 || arg->pr == -1 ? -1 : arg->pr + 2;
	print_trail(arg, core, &i, len);
	if (!arg->adj || arg->fs < len)
	{
		ft_putstr(out);
		core->printed += len;
	}
	ft_memdel((void **)&(arg->str));
	arg->str = NULL;
}

void	print_str(t_stat *arg, t_trail *core, int len, int i)
{
	char	*out;

	out = ft_cstr(core->ap);
	arg->str = out;
	len = ft_strlen(out);
	i = 0;
	arg->pr = arg->pr > len ? len : arg->pr;
	print_trail(arg, core, &i, len);
	if (!arg->adj || arg->fs < len)
	{
		ft_putstrn(out, (arg->pr != -1 ? arg->pr : len));
		core->printed += len;
	}
}

void	print_char(t_stat *arg, t_trail *core)
{
	char	*out;
	int		i;

	out = ft_cchr(core->ap);
	i = 0;
	while (i < arg->fs - 1)
	{
		if (i == 0 && arg->adj)
		{
			ft_putstr(out);
			core->printed += ft_strlen(out);
		}
		if (arg->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		++i;
		++(core->printed);
	}
	if (!arg->adj)
	{
		ft_putstr(out);
		core->printed += ft_strlen(out);
	}
	ft_memdel((void **)&out);
}

void		print_start(t_stat *arg, t_trail *core)
{
	if (arg->fmt == 'c')
		print_char(arg, core);
	else if (arg->fmt == 's')
		print_str(arg, core, 0, 0);
	else if (arg->fmt == 'p')
		print_ptr(arg, core, 0);
	else if (arg->fmt == 'i' || arg->fmt == 'd')
		print_int(arg, core, 0);
}
