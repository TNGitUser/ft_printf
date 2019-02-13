/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:38:52 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/12 11:10:01 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_is_cflag(char c)
{
	char	*cflags;
	char	*eflags;
	int		i;

	cflags = "cspdiouxXf%";
	eflags = "lLh#0+- ";
	i = 0;
	while (cflags[i] != '\0')
	{
		if (c == cflags[i])
			return (1);
		++i;
	}
	return (0);
}

size_t		ft_count(const char *str)
{
	size_t count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
			++count;
		++str;
	}
	return (count);
}

/*
**	ft_args: parse the string and retrieve the flag
*/

t_pargs		*ft_args(const char *str)
{
	t_pargs *args;
	int		i;
	int		c;

	if (!(args = malloc(sizeof(t_pargs))))
		return (NULL);
	i = 0;
	c = 0;
	if (!((args->pos) = malloc(sizeof(int) * ft_count(str))))
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			args->pos[c++] = i;
		++i;
	}
	args->cvn = c;
	if (!((args->df) = malloc(sizeof(char *) * c)))
		return (NULL);
	ft_init_ext(args);
	return (args);
}
