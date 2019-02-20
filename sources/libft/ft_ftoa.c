/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:24:07 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/20 16:28:28 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static long long	ft_rpart(long double n)
{
	return ((long long)n);
}

static int			ft_getlength(int c)
{
	int i;

	if (c == 0)
		return (1);
	i = 0;
	if (c == MIN_INT)
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

static void	ft_rparta(char *str, long rpart, int *len)
{
	if (rpart < 0)
	{
		str[(*len)--] = ((rpart % 10) * -1) + '0';
		rpart = rpart / 10;
		str[0] = '-';
		rpart = ft_abs(rpart);
	}
	while (rpart > 0)
	{
		str[(*len)--] = (rpart % 10) + '0';
		rpart = rpart / 10;
	}
}

static long double ft_findbmul(long double n, long double mul)
{
	long double bmul;

	bmul = 0;
	while (bmul < n)
		bmul += mul;
	return (bmul);
}

static void	ft_fparta(char *str, long double n, int *len, int precision)
{
	long double	fpart;
	long long	ftorpart;
	int			pr;
	int			last;

	pr = precision;
	printf("n : %Lf\n", n);
	printf("precision : %i\n", precision);
	printf("precision %% 10 : %i\n", precision % 10);
	fpart = (n - ft_rpart(n));
	while (pr > ft_findbmul(precision, 10))
	{
		fpart *= 10;
		pr -= 1;
	}
	if (precision > 10)
		ft_fparta(str, fpart, len, precision);
	fpart = (n - ft_rpart(n));
	ftorpart = ft_rpart(fpart);
	last = ftorpart % 10;
	ftorpart /= 10;
	if (last >= 5)
		ftorpart += 1;
	printf("{%lli}\n", ftorpart);
	while (ftorpart > 0)
	{
		str[(*len)--] = (ftorpart % 10) + '0';
		ftorpart = ftorpart / 10;
	}
	printf("l = %i\n", *len);
}

char		*ft_ftoa(long double n, int pr)
{
	char	*str;
	int		len;
	long	rpart;

	rpart = ft_rpart(n);
	len = ft_getlength(rpart);
	len += (n < 0 ? 1 : 0);
	printf("len : %i\n", len + 2 + pr);
	if (!(str = (char *)ft_memalloc(sizeof(char) * (len + 2 + pr))))
		return (NULL);
	len = len + 1 + pr;
	printf("Lne : %i\n", len);
	str[len--] = '\0';
	printf("Lne : %i\n", len - pr);
	printf("Lne : %i\n", len);
	ft_fparta(str, n, &len, pr);
	str[len--] = '.';
	ft_rparta(str, rpart, &len);
	return (str);
}
