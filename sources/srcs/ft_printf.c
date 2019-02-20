/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:19:52 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/20 15:37:14 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_iscflag(char c)
{
	char	*cflag;
	int		i;

	cflag = "cpsifdiouxX%";
	i = 0;
	while (cflag[i] != '\0')
	{
		if (c == cflag[i])
			return (1);
		++i;
	}
	return (0);
}

int		ft_ccount(const char *str)
{
	int	i;
	int flag;
	int c;

	flag = 1;
	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (flag && str[i] == '%')
		{
			++c;
			flag = 0;
		}
		else if (!flag && ft_iscflag(str[i]))
			flag = 1;
		++i;
	}
	return (c);
}

t_arg	*ft_getclist(const char *str, va_list ap, t_arg *la)
{
	t_arg	*head;
	int		i;
	int		k;

	i = 0;
	head = la;
	printf("Number of argument : %i\n", ft_ccount(str));
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			k = i + 1;
			while (!ft_iscflag(str[k]))
				++k;
			if (la == NULL)
			{
				la = ft_readarg(ft_strsub(str, i, k - i + 1), ap);
				head = la;
			}
			else
			{
				la->next = ft_readarg(ft_strsub(str, i, k - i + 1), ap);
				la = la->next;
			}
			if (la == NULL)
				exit(1);
		}
		++i;
	}
	return (head);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	t_arg	*la;
	t_arg	*l;

	la = NULL;
	va_start(ap, str);
	la = ft_getclist(str, ap, la);
	l = la;
	va_end(ap);
	while (la != NULL)
	{
		printf("%s\n", la->str);
		printf("\tData : -'%s'-\n", (char *)la->data);
		ft_dis_ef(la);
		la = la->next;
	}
	printf("%s\n\n", str);
	ft_format_str(str, l);
	ft_memdel((void **)&la);
	return (0);
}
