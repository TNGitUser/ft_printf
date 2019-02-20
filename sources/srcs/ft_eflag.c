/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:42:21 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/20 15:43:44 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_dis_ef(t_arg *arg)
{
	printf("Zeroed		: %i\n", arg->ef->zero);
	printf("Left align 	: %i\n", arg->ef->lalign);
	printf("Positive	: %i\n", arg->ef->positive);
	printf("Precision	: %i\n", arg->ef->pr);
	printf("Field size	: %i\n", arg->ef->fsize);
	printf("Alter form	: %i\n", arg->ef->af);
	printf("Modifier	: %i\n", arg->ef->lmod);
}

static void		ft_see_sign(t_arg *arg, char c)
{
	if (c == ' ' && arg->ef->positive != 1)
	{
		if (arg->ef->positive == 0)
			arg->ef->positive = 32;
	}
	else if (c == '+')
		arg->ef->positive = 43;
	if (arg->type >= 5 && arg->type <= 8)
		arg->ef->positive = 0;
}

static void		ft_is_ignored(t_arg *arg)
{
	t_eflag	*ef;

	ef = arg->ef;
	if (ef->zero != 0 && ef->lalign != 0)
		ef->zero = 0;
	if (arg->type >= 0 && arg->type <= 3 && ef->af == 1)
		ef->af = 0;
	if (arg->type >= 0 && arg->type <= 2)
	{
		if (arg->type != 1)
			ef->zero = 0;
		ef->positive = 0;
	}
}

static void		ft_set_ef(t_arg *arg)
{
	char	*str;
	int		i;

	str = arg->str;
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '0')
			arg->ef->zero = 1;
		else if (str[i] == '-')
			arg->ef->lalign = 1;
		else if (str[i] == '+' || str[i] == ' ')
			ft_see_sign(arg, str[i]);
		else if (str[i] <= '9' && str[i] >= '0')
		{
			if (str[i - 1] == '.')
				arg->ef->pr = ft_atoi((str + i));
			else
				arg->ef->fsize = ft_atoi((str + i));
			while (str[i] <= '9' && str[i] >= '0')
				++i;
		}
		else if (str[i] == '.' && (str[i + 1] > '9' || str[i + 1] < '0'))
			arg->ef->pr = 0;
		++i;
	}
	ft_is_ignored(arg);
}

void			ft_init_ef(t_arg *arg, int mod)
{
	t_eflag	*ef;

	if (!((arg->ef) = malloc(sizeof(t_eflag))))
		exit(1);
	ef = arg->ef;
	ef->af = 0;
	ef->zero = 0;
	ef->positive = 0;
	ef->fsize = 0;
	ef->pr = arg->type == 4 ? 6 : 0;
	ef->lalign = 0;
	ef->lmod = mod;
	ft_set_ef(arg);
}
