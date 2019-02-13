/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:28:30 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/11 13:24:39 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cchar(t_pargs *args, int v_char, int c)
{
	char *out;

	if (!(out = malloc(sizeof(char) * 2)))
		exit(1);
	out[0] = (char)v_char;
	out[1] = '\0';
	args->df[c] = out;
}

void	ft_cstr(t_pargs *args, char *str, int c)
{
	char *out;

	if (str != NULL)
	{
		if (!(out = ft_strdup(str)))
			exit(1);
	}
	else
		out = ft_strdup("(null)");
	args->df[c] = out;
}

void	ft_cptr(t_pargs *args, void *ptr, int c)
{
	char *out;
	char *tmp;

	if (!(out = ft_chex(ptr)))
		exit(1);
	tmp = out;
	out = ft_strjoin("0x", out);
	ft_memdel((void **)&tmp);
	args->df[c] = out;
}
