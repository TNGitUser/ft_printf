/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:42:21 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/14 07:17:09 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_set_ef(t_arg *arg)
{
	char	*str;
	int		i;

	str = arg->str;
	i = 1;
	while (str[i] !='\0')
	{
		if (str[i] == '0' && i == 0)
			arg->ef->zero = 1;
		else if (str[i] == '-')
			arg->ef->lalign = 1;
		else if (str[i] == '+' || str[i] == ' ')
			arg->ef->positive = str[i] == ' ' ? 2 : 1;
		else if (str[i] <= '9' && str[i] >= '0')
		{
			if (str[i - 1] == '.')
				arg->ef->pr = ft_atoi((str + i));
			else 
				arg->ef->fsize = ft_atoi((str + i));
			while (str[i] <= '9' && str[i] >= '0')
				++i;
		}
		++i;
	}
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
	ef->pr = 0;
	ef->lalign = 0;
	ef->lmod = mod;
	ft_set_ef(arg);
}
