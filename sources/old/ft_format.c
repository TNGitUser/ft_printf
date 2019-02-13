/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:25:57 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/13 10:14:41 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_cvlen(const char *str)
{
	size_t len;

	len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			++str;
			while (*str != ' ' && *str != '\n' && *(str + 1) != '\0')
			{
				++len;
				++str;
			}
		}
		++str;
	}
	return (len);
}

size_t			ft_getpsize(t_pargs *args, const char *str)
{
	size_t len;
	size_t cv;

	cv = 0;
	len = ft_strlen(str);
	len -= ft_cvlen(str);
	while (cv < args->cvn)
	{
		len += ft_strlen(args->df[cv]) + args->ext->fs[cv];
		if (args->ext->sign[cv] == 1 || args->ext->sign[cv] == 0)
			len += 1;
		++cv;
	}
	return (len);
}

void			ft_farg(t_pargs *args, char **out, int cv, size_t *xi)
{
	char	*cstr;
	int		sp;
	char	c;

	if (args->ext->prefix[cv] == 0)
		c = ' ';
	else
		c = '0';
	cstr = args->df[cv];
	sp = args->ext->fs[cv] - ft_strlen(cstr) - args->ext->pr[cv];
	while (cstr && *cstr != '\0')
	{
		if (args->ext->sign[cv] == 1 || args->ext->sign[cv] == 0)
		{
			if (args->ext->sign[cv] == 0 && cstr[0] != '-')
			{
				(*out)[*xi] = ' ';
				--sp;
			}
			if (cstr[0] == '-')
			{
				(*out)[*xi] = '-';
				cstr++;
			}
			else
			{
				(*out)[*xi] = '+';
				--sp;
			}
			++(*xi);
			args->ext->sign[cv] = -1;
		}
		while (sp > 0)
		{
			(*out)[(*xi)++] = c;
			--sp;
		}
		(*out)[*xi] = *cstr;
		++cstr;
		++(*xi);
	}
	ft_memdel((void **)&(args->df[cv]));
}

char			*ft_format(t_pargs *args, const char *str)
{
	char	*exitus;
	int		i;
	size_t	cv;
	size_t	xi;
	size_t	len;

	len = ft_getpsize(args, str);
	if (len == 0 || len >= 2147483647)
		exit(1);
	if (!(exitus = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	cv = 0;
	i = 0;
	xi = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_farg(args, &exitus, cv, &xi);
			while (str[i] != ' ' && str[i] != '\n' && str[i - 1] != '\0')
				++i;
			++cv;
		}
		exitus[xi] = str[i];
		++xi;
		++i;
	}
	ft_memdel((void **)&(args->df));
	ft_memdel((void **)&(args->pos));
	ft_free_ext(args->ext);
	exitus[len] = '\0';
	return (exitus);
}
