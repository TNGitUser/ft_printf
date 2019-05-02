/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:53:54 by lucmarti          #+#    #+#             */
/*   Updated: 2019/05/02 14:36:01 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(t_stat *arg, t_trail *core, int len)
{
	char	*out;
	int		i;

	i = 0;
	out = ft_cint(arg, core->ap);
	if (ft_strchr(out, '-'))
		arg->pr += arg->pr == -1 ? 0 : 1;
	len = ft_strlen(out);
	//printf("LEN : %i | FS : %i | PR : %i\n", len, arg->fs, arg->pr);
	arg->str = out;
	if ((out[0] == '0' || out[1] == '0') && (arg->pr == 0 || arg->pr == 1))
		out[out[0] == '0' ? 0 : 1] = '\0';
	print_trail(arg, core, &i, len);
	if (!arg->adj || arg->fs <= len)
	{
		ft_putstr(out);
		core->printed += len;
	}
	ft_memdel((void **)&(arg->str));
	arg->str = NULL;
}

void	print_per(t_stat *arg, t_trail *core, int len)
{
	char	*out;
	int		i;

	i = 0;
	out = "%";
	len = ft_strlen(out);
	arg->str = out;
	print_trail(arg, core, &i, len);
	if (!arg->adj || arg->fs <= len)
	{
		ft_putstr(out);
		core->printed += len;
	}
}
