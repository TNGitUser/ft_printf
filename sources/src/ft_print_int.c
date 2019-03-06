/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 08:57:20 by lucmarti          #+#    #+#             */
/*   Updated: 2019/03/06 17:10:14 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_signindex(t_arg *arg, size_t strl)
{
	size_t	sign_index;

	sign_index = 0;
	if (((char *)(arg->data))[0] == '-')
	{
		if (arg->ef->pr >= arg->ef->fsize || arg->ef->zero)
			sign_index = 0;
		else if ((size_t)arg->ef->pr < strl && (size_t)arg->ef->fsize > strl)
			sign_index = ft_abs(arg->ef->fsize - strl);
		else
			sign_index = ft_abs(arg->ef->fsize - arg->ef->pr);
	}
	return (sign_index);
}

static void	right_trailing(char *out, t_arg *arg, size_t strl, size_t *index)
{
	size_t	sign_index;

	sign_index = get_signindex(arg, strl);
	if (((char *)(arg->data))[0] == '-')
		strl--;
	while ((size_t)arg->ef->fsize > strl)
	{
		if (*index == sign_index)
			out[(*index)++] = ((char *)(arg->data))[0] == '-' ? '-' :
				arg->ef->positive;
		else if (arg->ef->zero)
			out[(*index)++] = '0';
		else
			out[(*index)++] = ' ';
		--(arg->ef->fsize);
	}
}

static void	left_trailing(char *out, t_arg *arg, size_t strl)
{
	int	index;

	index = 0;
	if (arg->ef->lalign && (size_t)arg->ef->fsize > strl)
		while ((size_t)arg->ef->fsize > strl)
		{
			if (arg->ef->zero)
				out[index++] = '0';
			else
				out[index++] = ' ';
			--(arg->ef->fsize);
		}
}

static void	ft_print_int(char *out, t_arg *arg)
{
	size_t	index;
	int		flag;
	size_t	tr_ind;

	tr_ind = ((char *)(arg->data))[0] == '-' ? 1 : 0;
	if (tr_ind == 1 && arg->ef->lalign && (flag = 1) == 1)
		tr_ind = 0;
	index = 0;
	if (arg->ef->pr != 0 && arg->ef->lalign)
		arg->ef->fsize -= arg->ef->pr - 3;
	if (!arg->ef->lalign)
		right_trailing(out, arg, ft_strlen((char *)(arg->data)), &index);
	arg->ef->pr += (arg->ef->pr == 0 ? ft_strlen((char *)(arg->data)) : 0);
	while (tr_ind < ft_strlen((char *)(arg->data)))
	{
		if (((char *)(arg->data))[0] == '-' && flag)
		{
			flag = 0;
			out[index++] = ((char *)(arg->data))[tr_ind++];
		}
		if ((size_t)arg->ef->pr > ft_strlen((char *)(arg->data)))
			out[index++] = '0';
		else
			out[index++] = ((char *)(arg->data))[tr_ind++];
		arg->ef->pr--;
	}
	left_trailing((out + index), arg, ft_strlen((char *)(arg->data)));
}

char		*printf_int(t_arg *arg)
{
	char	*out;
	size_t	length;

	length = 0;
	if (((char *)(arg->data))[0] == '-')
		arg->ef->pr += arg->ef->pr != 0 ? 1 : 0;
	if ((size_t)arg->ef->fsize > ft_strlen((char *)(arg->data)))
	{
		if ((size_t)arg->ef->pr > ft_strlen((char *)(arg->data)))
			length += arg->ef->pr;
		if (arg->ef->fsize > arg->ef->pr)
			length += arg->ef->fsize - arg->ef->pr;
	}
	else if ((size_t)arg->ef->pr > ft_strlen((char *)(arg->data)))
		length += arg->ef->pr;
	else
		length += ft_strlen((char *)(arg->data));
	printf("length : %li\n", length);
	if (!(out = malloc(sizeof(char) * (length + 1))))
		exit(1);
	out[length] = '\0';
	ft_print_int(out, arg);
	return (out);
}
