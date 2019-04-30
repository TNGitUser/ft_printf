/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:53:54 by lucmarti          #+#    #+#             */
/*   Updated: 2019/04/30 13:20:46 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(t_stat *arg, t_trail *core, int len)
{
	char	*out;
	int		i;

	i = 0;
	out = ft_cint(arg, core->ap);
	len = ft_strlen(out);
	arg->str = out;
	print_trail(arg, core, &i, len);
	if (!arg->adj || arg->fs < len)
	{
		ft_putstr(out);
		core->printed += len;
	}
	ft_memdel((void **)&(arg->str));
	arg->str = NULL;
}
