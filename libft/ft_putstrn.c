/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:07:45 by lucmarti          #+#    #+#             */
/*   Updated: 2019/04/30 14:16:35 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrn(char const *s, size_t n)
{
	size_t	u;

	u = 0;
	if (s)
		while (*s != '\0' && u < n)
		{
			ft_putchar(*s);
			++s;
			++u;
		}
}
