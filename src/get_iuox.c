/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iuox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:00:06 by lucmarti          #+#    #+#             */
/*   Updated: 2019/04/30 13:38:42 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cint(t_stat *la, va_list ap)
{
	char		*out;
	long long	nu;
	int			len;

	out = NULL;
	nu = 0;
	if (ft_strcmp(la->mod, "l") == 0)
		nu = va_arg(ap, long);
	else if (ft_strcmp(la->mod, "ll") == 0)
		nu = va_arg(ap, long long);
	else
		nu = va_arg(ap, int);
	if (!(out = ft_ltoa(nu)))
		out = ft_strdup("(null)");
	else
	{
		len = ft_strlen(out);
		while (len < la->pr)
		{
			out = ft_strjoinf("0", out);
			++len;
		}
	}
	return (out);
}
/*
   void	ft_coct(t_stat *la, va_list ap)
   {
   char		*out;
   long long	nu;

   out = NULL;
   nu = va_arg(ap, long long);
   if (!(out = ft_coct_aux(nu)))
   exit(1);
   la->data = (void *)out;
   }

   void		ft_cund(t_stat *la, va_list ap)
   {
   char			*out;
   unsigned long	nu;

   out = NULL;
   if (la->ef->lmod == 60)
   nu = va_arg(ap, int);
   else if (la->ef->lmod == 30)
   nu = va_arg(ap, int);
   else if (la->ef->lmod == 10)
   nu = va_arg(ap, unsigned long);
   else if (la->ef->lmod == 20)
   nu = va_arg(ap, unsigned long long);
   else
   nu = va_arg(ap, long long);
   if (!(out= ft_ltoa(nu)))
   out = ft_strdup("(null)");
   la->data = (void *)out;
   }

   static void	ft_upcase(char *str)
   {
   int i;

   i = 0;
   while (str[i] != '\0')
   {
   if (str[i] >= 'a' && str[i] <= 'f')
   str[i] -= 32;
   ++i;
   }
   }

   void		ft_cunh(t_stat *la, va_list ap, int type)
   {
   char				*out;
   long long	nu;

   out = NULL;
   if (la->ef->lmod == 60 || la->ef->lmod == 30)
   nu = va_arg(ap, int);
   else if (la->ef->lmod == 10)
   nu = va_arg(ap, unsigned long);
   else if (la->ef->lmod == 20)
   nu = va_arg(ap, unsigned long long);
   else
   nu = va_arg(ap, long long);
   if (!(out = ft_chex(NULL, nu, 1)))
   out = ft_strdup("(null)");
   if (type == 1)
   ft_upcase(out);
   la->data = (void *)out;
   }*/