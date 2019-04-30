/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 09:48:25 by lucmarti          #+#    #+#             */
/*   Updated: 2019/04/30 14:13:16 by lucmarti         ###   ########.fr       */
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
	ft_printf("- : [%020s]\n", "Zeros !");
	printf("* : [%.3s is string]\n", "This");
	ft_printf("- : [%.3s is string]\n", "This");
	printf("* : [%10.s is string]\n", "This");
	ft_printf("- : [%10.s is string]\n", "This");
	printf("* : [%s]\n", "");
	ft_printf("- : [%s]\n", "");
	printf("* : [%10s]\n", "");
	ft_printf("- : [%10s]\n\n", "");
	printf("* : [%.2s is a string]\n", "this");
	ft_printf("- : [%.2s is a string]\n", "this");
	printf("* : [%5.2s is a string]\n", "this");
	ft_printf("- : [%5.2s is a string]\n", "this");
	// ------------------------------------------------------------------------
	// ------------------------------------------ char test -----------------
	printf("\n######## CHAR ########\n");
	printf("* : [%c %c %c %c %c]\n", 'a', 75, 10, '@', '9');
	ft_printf("- : [%c %c %c %c %c]\n", 'a', 75, 10, '@', '9');
	printf("* : [%c %2c]\n", 0, NULL);
	ft_printf("- : [%c %2c]\n\n", 0, NULL);
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
