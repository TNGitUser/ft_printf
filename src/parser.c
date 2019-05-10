/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:19:06 by lucmarti          #+#    #+#             */
/*   Updated: 2019/05/09 15:03:14 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	arg_init(t_stat *arg)
{
	arg->flags = 0;
	arg->alt = 0;
	arg->adj = 0;
	arg->form = 0;
	arg->zero = 0;
	arg->fs = 0;
	arg->pr = -1;
	arg->fmt = 0;
	arg->mod = NULL;
	arg->str = NULL;
}

void	arg_profs(char *text, int *cur, t_stat *arg, int type)
{
	if (type == 0)
		arg->fs = ft_atoi(text + *cur);
	else
	{
		arg->pr = ft_atoi(text + *cur + 1);
		++(*cur);
	}
	while (text[*cur] != '\0' && (text[*cur] >= '0' && text[*cur] <= '9'))
		++(*cur);
	--(*cur);
}

void	arg_mod(char *text, int *cur, t_stat *arg)
{
	int i;

	i = *cur;
	while (text[i] != '\0' && is_mod(text[i]))
		++i;
	*cur += (i - 1 - *cur);
	--i;
	while (i >= 0)
	{
		if (!is_mod(text[i]) || arg->mod)
			break ;
		if (text[i] == 'l' && (text[i - 1] == 'l' || text[i - 1] != 'l'))
			arg->mod = text[i - 1] == 'l' ? "ll" : "l";
		else if (text[i] == 'h' && (text[i - 1] == 'h' || text[i - 1] != 'h'))
			arg->mod = text[i - 1] == 'h' ? "hh" : "h";
		else if (text[i] == 'L' || text[i] == 'j')
			arg->mod = (text[i] == 'L' ? "L" : "j");
		else if (text[i] == 'z')
			arg->mod = "z";
		if (text[i - 1] == 'z' || text[i - 1] == 'j')
			arg->mod = text[i - 1] == 'j' ? "j" : "z";
		--i;
	}
	return ;
}

void	arg_set(t_stat *arg, char *text, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (text[i] == '#')
			arg->alt = 1;
		else if (text[i] == '0')
			arg->zero = 1;
		else if (text[i] == '-')
			arg->adj = 1;
		else if (text[i] == ' ' || text[i] == '+')
			arg->form = (text[i] == ' ' && arg->form != 2) ? 1 : 2;
		else if ((text[i] >= '1' && text[i] <= '9') || text[i] == '.')
			arg_profs(text, &i, arg, (text[i] == '.' ? 1 : 0));
		else if (text[i] == 'L' || text[i] == 'l' || text[i] == 'h'
				|| text[i] == 'j' || text[i] == 'z')
			arg_mod(text, &i, arg);
		else if (is_type(text[i]))
			arg->fmt = text[i];
		++i;
	}
}

/*
**	parse_arg : function that will read part of the text till the conversion
**		type flag (from % to %/i/c/p/s/f/d/o/u/x/X) and will retrieve the
**		correct parameters (flags, field width, precision, type, modifier).
*/

int		parse_arg(char *text, t_trail *core)
{
	int		i;
	t_stat	arg;

	i = 1;
	arg_init(&arg);
	while (text[i] != '\0' && !is_type(text[i]))
	{
		if (is_unknown(text[i]))
			return (i);
		++i;
	}
	if (text[i] == '\0')
		return (i);
	arg_set(&arg, text, text[i] == '\0' ? i : i + 1);
	set_priorities(&arg);
	print_start(&arg, core);
	return (text[i] == '\0' ? i : i + 1);
}
