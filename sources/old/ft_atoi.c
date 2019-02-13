/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:50:23 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/13 10:05:16 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void	ft_issp(const char *str, int *i)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r')
	{
		++str;
		++(*i);
	}
}

int			ft_atoi(const char *str, int *i)
{
	int			sign;
	int			nd;
	long long	ret;
	char		*src;

	sign = 0;
	ret = 0;
	nd = 0;
	src = (char *)str;
	ft_issp(str, i);
	sign = 0;
	while (*str >= 48 && *str <= 57)
	{
		++nd;
		ret *= 10;
		ret += (*str - 48);
		++str;
		if ((ret > 9223372036854775807 || ret < 0) && nd >= 18)
			return (sign == 0 ? -1 : 0);
		*i += 1;
	}
	return (sign ? 0 - (int)ret : (int)ret);
}
