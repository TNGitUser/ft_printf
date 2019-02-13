/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:24:07 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/11 16:23:34 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

static int	ft_getlength(int c)
{
	int i;

	if (c == 0)
		return (1);
	i = 0;
	if (c == -2147483648)
	{
		i = 1;
		c = c / 10;
	}
	c = ft_abs(c);
	while (c > 0)
	{
		++i;
		c = c / 10;
	}
	return (i);
}

char		*ft_itoa(long n)
{
	char	*str;
	int		len;

	len = ft_getlength(n);
	len += (n < 0 ? 1 : 0);
	if (!(str = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	str[len] = '0';
	if (n < 0)
	{
		str[len--] = ((n % 10) * -1) + '0';
		n = n / 10;
		str[0] = '-';
		n = ft_abs(n);
	}
	while (n > 0)
	{
		str[len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
