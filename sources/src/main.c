/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:15:09 by lucmarti          #+#    #+#             */
/*   Updated: 2019/03/06 17:10:28 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <float.h>

int	main(void)
{

	ft_printf("[%50.15i]\n", -15);
	printf("[%50.15i]\n", -15);

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
	printf("%-10.5li\n", 15);//32768);*/
	//ft_printf("%-10.15%o\n");
	//printf("%-10.15%o\n");*/
	//ft_printf("Bonjour, je suis %.1s %.1s, j'ai [%lli] ans.\n", "Lucas", "Martin", LONG_MIN);
	//printf("Bonjour, je suis [%.1s], j'ai     [%lli] ans.\n",  "Martin", LONG_MIN);
	//ft_printf("[%.20f]\n", .9);//9999.15640576454555555000000000000000000000000000500);
	//printf("[%.20f]\n", .9);//9999.1564057645455555000000000000000000000000000500);
	//printf("[%i]\n", (1 << 31) - 1);
	//printf("[%lli]\n", (long long)90000000002200 << 2);
//	printf("								 [%.9999993899999999f]\n", 9999.156405764);
	return (0);
}
