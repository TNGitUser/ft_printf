/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:15:09 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/13 17:58:39 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("%s %% %s %lli %li %hd %hhd %p\n\n");
	ft_printf("Ceci est un test.\n\n");
	ft_printf("Ceci %s un %s.\n\n", "est", "test");
	return (0);
}
