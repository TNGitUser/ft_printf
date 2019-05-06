/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iuo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:51:03 by lucmarti          #+#    #+#             */
/*   Updated: 2019/05/06 12:46:41 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_arg(long long *nu, va_list ap, t_stat *la)
{
	*nu = 0;
	if (ft_strcmp(la->mod, "l") == 0 || la->fmt == 'D')
		*nu = va_arg(ap, long);
	else if (ft_strcmp(la->mod, "ll") == 0)
		*nu = va_arg(ap, long long);
	else if ((ft_strcmp(la->mod, "h") == 0))
		*nu = (short int)(va_arg(ap, int));
	else if (ft_strcmp(la->mod, "hh") == 0)
		*nu = (signed char)(va_arg(ap, int));
	else
		*nu = va_arg(ap, int);
	return (0);
}

void		ft_addz(char **out, t_stat *la, int len, long long nu)
{
	while (len < la->pr || (la->zero && len < la->fs))
	{
		if (nu < 0)
			*out = ft_straddc('0', *out, '-');
		else
			*out = ft_strjoinf("0", *out);
		++len;
	}
}

char		*ft_cint(t_stat *la, va_list ap)
{
	char		*out;
	long long	nu;
	int			len;

	out = NULL;
	if (ft_get_arg(&nu, ap, la) || !(out = ft_ltoa(nu)))
		out = ft_strdup("(null)");
	else
	{
		len = ft_strlen(out) - ((out[0] == '-') && (la->pr > 0) ? 1 : 0);
		if (!(out[0] == '-'))
			len += ((la->form != 0 ? 1 : 0) - (la->pr > len
						&& la->form != 0 ? 1 : 0));
		ft_addz(&out, la, len, nu);
		if (la->form != 0 && nu >= 0)
		{
			out = ft_strjoinf(la->form == 2 ? "+" : " ", out);
			la->pr += la->pr == -1 ? 0 : 1;
		}
	}
	return (out);
}

char		*ft_coct(t_stat *la, va_list ap)
{
	char		*out;
	long long	nu;

	out = NULL;
	nu = va_arg(ap, long long);
	if (!(out = ft_coct_aux(nu)))
		out = ft_strdup("(null)");
	ft_addz(&out, la, ft_strlen(out), nu);
	if (la->alt == 1 && out[0] != '0' && ft_strcmp(out, "(null)") != 0)
		out = ft_strjoinf("0", out);
	return (out);
}

char		*ft_cund(t_stat *la, va_list ap)
{
	char			*out;
	unsigned long	nu;

	out = NULL;
	if (ft_strcmp(la->mod, "l") == 0 || la->fmt == 'U')
		nu = va_arg(ap, unsigned long);
	else if (ft_strcmp(la->mod, "hh") == 0)
		nu = (unsigned char)va_arg(ap, unsigned int);
	else if (ft_strcmp(la->mod, "h") == 0)
		nu = (unsigned short)va_arg(ap, unsigned int);
	else if (ft_strcmp(la->mod, "ll") == 0)
		nu = va_arg(ap, unsigned long long);
	else
		nu = va_arg(ap, unsigned int);
	if (!(out = ft_ltoa(nu)))
		out = ft_strdup("(null)");
	ft_addz(&out, la, ft_strlen(out), nu);
	return (out);
}
