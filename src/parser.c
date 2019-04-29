/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:19:06 by lucmarti          #+#    #+#             */
/*   Updated: 2019/04/29 15:42:12 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	arg_init(t_stat *arg)
{
	arg->flags = 0;
	arg->alt = 0;
	arg->adj = 0;
	arg->form = 0;
	arg->zero = 0;
	arg->fs = 0;
	arg->pr = 0;
	arg->fmt = 0;
	arg->mod = NULL;
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
	while (text[i] != '\0' && !is_type(text[i]))
		++i;
	*cur += (i - 1 - *cur);
	--i;
	while (i >= 0)
	{
		if ((text[i] != 'l' && text[i] != 'h' && text[i] != 'L') || arg->mod)
			break ;
		if (text[i] == 'l' && text[i - 1] == 'l')
			arg->mod = "ll";
		else if (text[i] == 'l' && text[i - 1] != 'l')
			arg->mod = "l";
		else if (text[i] == 'h' && text[i - 1] == 'h')
			arg->mod = "hh";
		else if (text[i] == 'h' && text[i - 1] != 'h')
			arg->mod = "h";
		else if (text[i] == 'L')
			arg->mod = "L";
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
			arg->form = text[i] == ' ' && arg->form != 2 ? 1 : 2;
		else if ((text[i] >= '1' && text[i] <= '9') || text[i] == '.')
			arg_profs(text, &i, arg, (text[i] == '.' ? 1 : 0));
		else if (text[i] == 'l' || text[i] == 'h' || text[i] == 'L')
			arg_mod(text, &i, arg);
		else if (is_type(text[i]))
			arg->fmt = text[i];
		++i;
	}
}

void	debug_var(t_stat *arg)
{
	printf("\n\n");
	printf("%10s : %i\n", "flags", arg->flags);
	printf("%10s : %i\n", "alt", arg->alt);
	printf("%10s : %i\n", "adj", arg->adj);
	printf("%10s : %i\n", "form", arg->form);
	printf("%10s : %i\n", "zero", arg->zero);
	printf("%10s : %i\n", "fsize", arg->fs);
	printf("%10s : %i\n", "precision", arg->pr);
	printf("%10s : %s\n", "modifiers", arg->mod);
	printf("%10s : %c\n", "fmt", arg->fmt);
	printf("\n\n");
}

/*
**	parse_arg : function that will read part of the text till the conversion
**		type flag (from % to %/i/c/p/s/f/d/o/u/x/X) and will retrieve the
**		correct parameters (flags, field width, precision, type, modifier).
*/

int		parse_arg(char *text)
{
	int		i;
	t_stat	arg;

	i = 0;
	arg_init(&arg);
	while (text[i] != '\0' && !is_type(text[i]))
		++i;
	if (text[i] == '\0')
		err_die("\nft_printf: Bad conversion");
	arg_set(&arg, text, text[i] == '\0' ? i : i + 1);
	set_priorities(&arg);
	debug_var(&arg);
	return (text[i] == '\0' ? i : i + 1);
}
