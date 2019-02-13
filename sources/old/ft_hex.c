/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:33:06 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/11 11:47:29 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_hcount(long unsigned n)
{
	size_t c;

	c = 0;
	while (n > 0)
	{
		++c;
		n = n / 16;
	}
	return (c);
}

char		*ft_chex(void *ptr)
{
	char			*out;
	size_t			len;
	long unsigned	lptr;
	long unsigned	res;

	lptr = (long unsigned)ptr;
	len = ft_hcount(lptr);
	if (!(out = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	out[len] = '\0';
	len--;
	res = 0;
	while (lptr > 0)
	{
		res = lptr % 16;
		lptr = lptr / 16;
		if (res < 10)
			out[len] = res + '0';
		else
			out[len] = (res - 10) + 'a';
		--len;
	}
	return (out);
}
