/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 09:57:22 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/12 13:08:41 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_getendc(const char *str)
{
	int i;

	i = 0;
	while (!ft_is_cflag(str[i]))
		++i;
	++i;
	return (i);
}

int		ft_printf(const char *str, ...)
{
	t_pargs	*args;
	va_list	ap;
	size_t	c;
	size_t	i;
	char	*exitus;

	if (!(args = ft_args(str)))
		return (1);
	c = 0;
	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			++i;
			ft_set_ext(args, c, str + i, ft_getendc(str + i));
			while (!ft_is_cflag(str[i]))
				++i;
			if (str[i] == 'c')
				ft_cchar(args, va_arg(ap, int), c);
			else if (str[i] == 's')
				ft_cstr(args, va_arg(ap, char *), c);
			else if (str[i] == 'p')
				ft_cptr(args, va_arg(ap, void *), c);
			else if (str[i] == 'i')
				ft_ci(args, va_arg(ap, int), c);
			++c;
		}
		++i;
	}
	va_end(ap);
	exitus = ft_format(args, str);
	write(1, exitus, ft_strlen(exitus));
	ft_memdel((void **)&exitus);
	ft_memdel((void **)&args);
	return (0);
}
