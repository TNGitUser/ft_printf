/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:15:09 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/18 13:42:35 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	/*void	*ptr;

	ptr = malloc(1);
	ft_printf("%s %% %s %lli %li %hd %hhd %p\n\n", "wesh", "bonj\0our",
			1, 2, 45, 78, ptr);
	ft_printf("Ceci est un test.\n\n");
	ft_printf("Ceci %s un %s.\n\n", "est", "test");
	ft_printf("Autre %c\n", 't');
	ft_printf("Encore %o %o\n", 8, 7);
	ft_printf("AGAIN %x %X\n", 4095, 4095);
	printf("\n\n%s %% %s %lli %li %hd %hhd %p\n\n", "wesh",
			"bonj\0our", (long long)100000000000000000,
			20000000000, (short)45, (char)78, ptr);
	free(ptr);
	ft_printf("%-10.5hli\n", 15);
	printf("%-10.5li\n", (long long)9223372036854775807);//32768);
	//ft_printf("%-10.15%o\n");
	//printf("%-10.15%o\n");*/
	ft_printf("Bonjour, je suis %15s %15s, j'ai %0+15i ans.\n", "Lucas", "Martin", 22);
	printf("Bonjour, je suis %15s %15s, j'ai %0+15i ans.\n", "Lucas", "Martin", 22);
	return (0);
}
