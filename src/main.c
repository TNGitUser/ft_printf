/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 09:48:25 by lucmarti          #+#    #+#             */
/*   Updated: 2019/04/30 11:57:35 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("* : printf\n- : ft_printf\n\n");
	// ------------------------------------------ Pure text -------------------
	printf("######## PURE TEXT ########\n");
	printf("* : This is anything but text\n");
	ft_printf("- : This is anything but text\n\n");
	// ------------------------------------------------------------------------
	// ------------------------------------------ string test -----------------
	printf("\n######## STRINGS ########\n");
	printf("* : [%s]\n", "This is anything but a string");
	ft_printf("- : [%s]\n", "This is anything but a string");
	printf("* : [%15.7s]\n", "Truncated text !");
	ft_printf("- : [%15.7s]\n", "Truncated text !");
	printf("* : [%-5s]\n", "Left padding (in fact no padding)!");
	ft_printf("- : [%-5s]\n", "Left padding (in fact no padding)!");
	printf("* : [%-35s]\n", "Left padding !");
	ft_printf("- : [%-35s]\n", "Left padding !");
	printf("* : [%35s]\n", "Right padding !");
	ft_printf("- : [%35s]\n", "Right padding !");
	printf("* : [%.s]\n", "Null precision !");
	ft_printf("- : [%.s]\n", "Null precision !");
	printf("* : [%-20.187s]\n", "Null precision !");
	ft_printf("- : [%-20.187s]\n", "Null precision !");
	printf("* : [%020s]\n", "Zeros !");
	ft_printf("- : [%020s]\n\n", "Zeros !");
	// ------------------------------------------------------------------------
	// ------------------------------------------ char test -----------------
	printf("\n######## CHAR ########\n");
	printf("* : [%c %c %c %c %c]\n", 'a', 75, 10, '@', '9');
	ft_printf("- : [%c %c %c %c %c]\n\n", 'a', 75, 10, '@', '9');
	// ------------------------------------------------------------------------
	// ------------------------------------------ integer test ----------------
	printf("\n######## INTEGER ########\n");
	printf(" : %i\n", printf("* test %i", 15));
	printf(" : %i\n", ft_printf("- test %i", 15));
	printf("* : [%15i]\n", 25);
	ft_printf("- : [%15i]\n\n", 25);
	printf("* : [%5.15i]\n", 25);
	ft_printf("- : [%5.15i]\n\n", 25);
	// ------------------------------------------------------------------------
	// ------------------------------------------ pointer test ----------------
	printf("\n######## POINTER ########\n");
	char	*ptr;

	ptr = "Test0";
	printf(" : %i\n", printf("* : [%p]", ptr));
	printf(" : %i\n", ft_printf("- : [%p]", ptr));
	printf(" : %i\n", printf("* : [%20.15p]", ptr));
	printf(" : %i\n", ft_printf("- : [%20.15p]", ptr));
	printf(" : %i\n", printf("* : [%-20.p]", ptr));
	printf(" : %i\n", ft_printf("- : [%-20.p]", ptr));
	// ------------------------------------------------------------------------
	return (0);
}
