/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 09:49:20 by lucmarti          #+#    #+#             */
/*   Updated: 2019/04/29 12:43:34 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_trail	*trail_init(char *text)
{
	t_trail *core;

	if (!(core = malloc(sizeof(t_trail) * 1)))
		err_die("\nft_printf: Init failed");
	core->ftext = text;
	core->printed = 0;
	return (core);
}

void	trail_free(t_trail *core)
{
	if (!core)
		return ;
	va_end(core->ap);
	ft_memdel((void **)&core);
}
