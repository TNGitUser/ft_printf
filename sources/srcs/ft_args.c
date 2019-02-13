/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:29:15 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/13 15:14:54 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_readarg(char *str, va_list ap)
{
	int		type;
	size_t	len;

	len = ft_strlen(str);
	(void)ap;
	(void)type;
	printf("%s\n", str);
	printf("%li\n", len);
	ft_memdel((void **)&str);
}
