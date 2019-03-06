/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 08:20:26 by lucmarti          #+#    #+#             */
/*   Updated: 2019/03/06 11:15:41 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	left_trailing(char *out, t_arg *arg)
{
	int	index;

	index = 0;
	if (arg->ef->lalign &&
			(size_t)arg->ef->fsize > ft_strlen((char *)(arg->data)))
		while ((size_t)arg->ef->fsize > ft_strlen((char *)(arg->data)))
		{
			if (arg->ef->zero)
				out[index++] = '0';
			else
				out[index++] = ' ';
			--(arg->ef->fsize);
		}
}

static void	ft_print_string(char *out, t_arg *arg)
{
	size_t	index;
	size_t	tr_ind;

	tr_ind = 0;
	index = 0;
	if (!arg->ef->lalign &&
			(size_t)arg->ef->fsize > ft_strlen((char *)(arg->data)))
		while ((size_t)arg->ef->fsize > ft_strlen((char *)(arg->data)))
		{
			if (arg->ef->zero)
				out[index++] = '0';
			else
				out[index++] = ' ';
			--(arg->ef->fsize);
		}
	arg->ef->pr += (arg->ef->pr == 0 ? ft_strlen((char *)(arg->data)) : 0);
	while (arg->ef->pr > 0 && tr_ind < ft_strlen((char *)(arg->data)))
	{
		out[index] = ((char *)(arg->data))[tr_ind++];
		++index;
		arg->ef->pr--;
	}
	left_trailing(out + index, arg);
}

char		*printf_string(t_arg *arg)
{
	char	*out;
	size_t	length;

	length = 0;
	length += (size_t)arg->ef->fsize > ft_strlen((char *)(arg->data)) ?
		arg->ef->fsize : ft_strlen((char *)(arg->data));
	length += (size_t)arg->ef->pr > ft_strlen((char *)(arg->data)) ? 0 :
		-(ft_strlen((char *)(arg->data)) - arg->ef->pr);
	if (!(out = malloc(sizeof(char) * (length + 1))))
		exit(1);
	out[length] = '\0';
	ft_print_string(out, arg);
	return (out);
}
