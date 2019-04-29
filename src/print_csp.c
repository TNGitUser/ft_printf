/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:58:13 by lucmarti          #+#    #+#             */
/*   Updated: 2019/04/29 16:14:47 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_type_method(char t)
{
	if (type == 'c')
		return (0);
	else if (type == 's')
		return (1);
	else if (type == 'p')
		return (2);
	else if (type == 'd')
		return (3);
	else if (type == 'i')
		return (4);
	else if (type == 'o')
		return (5);
	else if (type == 'u')
		return (6);
	else if (type == 'x')
		return (7);
	else if (type == 'X')
		return (8);
	return (9);
}

void	print_start(t_stat *arg, t_trail *core)
{
	int	method;

	method = get_type_method(arg->fmt);

}
