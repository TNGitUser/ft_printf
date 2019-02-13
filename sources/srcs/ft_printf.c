/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:19:52 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/13 15:17:35 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_iscflag(char c)
{
	char	*cflag;
	char	*eflag;
	int		i;

	cflag = "cpsifdiouxX%";
	eflag = "#+-. ";
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

t_carg	*ft_getclist(const char *str, va_list ap)
{
	t_carg	*carg;
	t_list	*head;
	t_list	*cur;
	int		i;
	int		k;;

	i = 0;
	if (!(carg = malloc(sizeof(t_carg))))
		exit(1);
	carg->cn = ft_ccount(str);
	printf("Number of argument : %i\n", carg->cn);
	head = ft_lstnew(NULL, 0);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			k = i + 1;
			while (!ft_iscflag(str[k])) 
				++k;
			ft_readarg(ft_strsub(str, i, k - i + 1), ap);
		}
		++i;
	}
	cur = head->next;
	while (cur != NULL)
	{
		printf("Arg : %s\n", (char *)cur->content);
		cur = cur->next;
	}
	ft_lstfree_all(&head);
	return (carg);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_carg	*carg;

	va_start(ap, str);
	carg = ft_getclist(str, ap);
	va_end(ap);
	printf("%s", str);
	ft_memdel((void **)&carg);
	return (0);
}
