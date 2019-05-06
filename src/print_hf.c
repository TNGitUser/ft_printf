/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:54:02 by lucmarti          #+#    #+#             */
/*   Updated: 2019/05/06 11:48:26 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x(t_stat *arg, t_trail *core, int len, int type)
{
	char	*out;
	int		i;

	i = 0;
	out = ft_cunh(arg, core->ap, type);
	len = ft_strlen(out);
	if (arg->pr != -1 && arg->pr < len)
		arg->pr = len;
	arg->str = out;
	print_trail(arg, core, &i, len);
	if (!arg->adj || arg->fs <= len)
	{
		ft_putstr(out);
		core->printed += len;
	}
	ft_memdel((void **)&(out));
	arg->str = NULL;
}
