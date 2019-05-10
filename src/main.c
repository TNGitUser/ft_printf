/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 09:48:25 by lucmarti          #+#    #+#             */
/*   Updated: 2019/05/09 12:56:40 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

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
	printf("* : [%s %s]\n", NULL, "this");
	ft_printf("- : [%s %s]\n", NULL, "this");
	// ------------------------------------------------------------------------
	// ------------------------------------------ char test -----------------
	printf("\n######## CHAR ########\n");
	printf("* : [%c %c %c %c %c]\n", 'a', 75, 10, '@', '9');
	ft_printf("- : [%c %c %c %c %c]\n", 'a', 75, 10, '@', '9');
	printf("* : [%c %2c]\n", 0, NULL);
	ft_printf("- : [%c %2c]\n\n", 0, NULL);
	printf("* : [% c]\n", 0);
	ft_printf("- : [% c]\n\n", 0);
	printf("* : null [%c] and text\n", 0);
	ft_printf("- : null [%c] and text\n", 0);
	printf("* : null [%c] and text\n", 0);
	ft_printf("- : null [%c] and text\n", 0);
	// ------------------------------------------------------------------------
	// ------------------------------------------ integer test ----------------
	printf("\n######## INTEGER ########\n");
	printf(" : %i\n", printf("* test %i", 15));
	printf(" : %i\n", ft_printf("- test %i", 15));
	printf("* : [%15i]\n", 25);
	ft_printf("- : [%15i]\n", 25);
	printf("* : [%5.15i]\n", 25);
	ft_printf("- : [%5.15i]\n", 25);
	printf("* : [%05d]\n", -42);
	ft_printf("- : [%05d]\n", -42);
	printf("* : [%   5d]\n", 351897);
	ft_printf("- : [%   5d]\n", 351897);
	printf("* : [%#0+   --5d]\n", 8712);
	ft_printf("- : [%#0+ --5d]\n", 8712);
	printf("* : [%#0+   --5d]\n", 2147483647);
	ft_printf("- : [%#0+   --5d]\n", 2147483647);
	printf("* : [%#0+   --5d]\n", -2147483648);
	ft_printf("- : [%#0+   --5d]\n", -2147483648);
	printf("* : [%hi]\n", -2147483648);
	ft_printf("- : [%hi]\n", -2147483648);
	printf("* : [%hi]\n", 32767);
	ft_printf("- : [%hi]\n", 32767);
	printf("* : [%+i]\n", 0);
	ft_printf("- : [%+i]\n", 0);
	printf("* : [%+i]\n", -1);
	ft_printf("- : [%+i]\n", -1);
	printf("* : [%#0+   --5lli]\n", 9223372036854775807);
	ft_printf("- : [%#0+   --5lli]\n", 9223372036854775807);
	printf("* : [%#0+   lli]\n", -9223372036854775808);
	ft_printf("- : [%#0+   lli]\n", -9223372036854775808);
	printf("* : [%#0+   lli]\n", -9223372036854775809);
	ft_printf("- : [%#0+   lli]\n", -9223372036854775809);
	printf("* : [%i]\n", 9223372036854775808);
	ft_printf("- : [%i]\n", 9223372036854775808);
	printf("* : [%hhd]\n", 128);
	ft_printf("- : [%hhd]\n", 128);
	printf("* : [% 10.5d]\n", 4242);
	ft_printf("- : [% 10.5d]\n", 4242);
	printf("* : [% .3d]\n", 42);
	ft_printf("- : [% .3d]\n", 42);
	printf("* : [%03.2d]\n", -42);
	ft_printf("- : [%03.2d]\n", -42);
	printf("* : [%.10d]\n", -42);
	ft_printf("- : [%.10d]\n", -42);
	printf("* : [%.d] [%.0d]\n", 0, 0);
	ft_printf("- : [%.d] [%.0d]\n", 0, 0);
	printf("* : [% .d] [%+.0d]\n", -0, 0);
	ft_printf("- : [% .d] [%+.0d]\n", -0, 0);
	printf("* : [%0+5d]\n", 42);
	ft_printf("- : [%0+5d]\n", 42);
	printf("* : [%0+5d]\n", -42);
	ft_printf("- : [%0+5d]\n", -42);
	printf("* : [%0+5.3d]\n", 42);
	ft_printf("- : [%0+5.3d]\n", 42);
	printf("* : [%lu]\n", -876);
	ft_printf("- : [%lu]\n", -876);
	printf("* : [%jd]\n", -92);
	ft_printf("- : [%jd]\n", -92);
	printf("* : [%jd]\n", 9223372036854775807);
	ft_printf("- : [%jd]\n", 9223372036854775807);
	printf("* : [%zhd]\n", 4294967296);
	ft_printf("- : [%zhd]\n", 4294967296);
	printf("@main_ftprintf: {%####0000 33..1..#00d}\n", 256);
	ft_printf("@main_ftprintf: {%####0000 33..1..#00d}\n", 256);
	printf("@main_ftprintf: {%###-#0000 33...12..#0+0d}\n", 256);
	ft_printf("@main_ftprintf: {%###-#0000 33...12..#0+0d}\n", 256);
	// ------------------------------------------------------------------------
	// ------------------------------------------ unsigned test ---------------	
	printf("\n######## UNSIGNED ########\n");
	printf("* : [%u]\n", 0);
	ft_printf("- : [%u]\n", 0);
	printf("* : [%u]\n", -1);
	ft_printf("- : [%u]\n", -1);
	printf("* : [%u]\n", 4294967295);
	ft_printf("- : [%u]\n", 4294967295);
	printf("* : [%u]\n", 4294967296);
	ft_printf("- : [%u]\n", 4294967296);
	printf("* : [%lu]\n", -42);
	ft_printf("- : [%lu]\n", -42);
	printf("* : [%llu]\n", -4200);
	ft_printf("- : [%llu]\n", -4200);
	printf("* : [%lu]\n", ULONG_MAX);
	ft_printf("- : [%lu]\n", ULONG_MAX);
	printf("* : [%U]\n", ULONG_MAX);
	ft_printf("- : [%U]\n", ULONG_MAX);
	printf("* : [%hU]\n", ULONG_MAX);
	ft_printf("- : [%hU]\n", ULONG_MAX);
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
	printf(" : %i\n", printf("* : [%#0+ 78.5p]", ptr));
	printf(" : %i\n", ft_printf("- : [%#0+ 78.1p]", ptr));
	printf(" : %i\n", printf("* : [%#0+ -78.5p]", ptr));
	printf(" : %i\n", ft_printf("- : [%#0+ -78.1p]", ptr));
	// ------------------------------------------------------------------------
	// ------------------------------------------ % test ----------------------
	printf("\n######## % ########\n");
	
	printf("* : [%45%]\n");
	ft_printf("- : [%45%]\n");
	printf("* : [%-5%]\n");
	ft_printf("- : [%-5%]\n");
	printf("* : [% %]\n");
	ft_printf("- : [% %]\n");
	printf("* : [%+.5%]\n");
	ft_printf("- : [%+.5%]\n");
	printf("* : [%+.%]\n");
	ft_printf("- : [%+.%]\n");
	printf("* : [% Zy fait chaud ici]\n");
	ft_printf("- : [% Zy fait chaud ici]\n");
	printf("* : [% zy fait chaud ici %%]\n");
	ft_printf("- : [% zy fait chaud ici %%]\n");
	printf("* : [%      Zooooooo]\n");
	ft_printf("* : [%      Zooooooo]\n");
	printf("* : [%%%]\n");
	ft_printf("* : [%%%]\n");
	printf("* : [%05.%]\n", 0);
	ft_printf("- : [%05.%]\n", 0);
	printf("* : [%05.0%]\n", 0);
	ft_printf("- : [%05.0%]\n", 0);
	// ------------------------------------------------------------------------
	// ------------------------------------------ octal test ------------------
	printf("\n######## OCTAL ########\n");
	printf("* : [%#.o %#.0o]\n", 0, 0);
	ft_printf("- : [%#.o %#.0o]\n", 0, 0);
	printf("* : [%.o %.0o]\n", 0, 0);
	ft_printf("- : [%.o %.0o]\n", 0, 0);
	printf("* : [%o]\n", 0);
	ft_printf("- : [%o]\n", 0);
	printf("* : [%.10o]\n", 42);
	ft_printf("- : [%.10o]\n", 42);
	printf("* : [%#6o]\n", 2500);
	ft_printf("- : [%#6o]\n", 2500);
	printf("- : [%-#6o]\n", 2500);
	ft_printf("- : [%-#6o]\n", 2500);
	printf("- : [%lo]\n", ULONG_MAX);
	ft_printf("- : [%lo]\n", ULONG_MAX);
	printf("- : [%llo]\n", ULLONG_MAX);
	ft_printf("- : [%llo]\n", ULLONG_MAX);
	// ------------------------------------------------------------------------
	// ------------------------------------------ hexa test -------------------
	printf("\n######## HEXADECIMAL ########\n");
	printf("* : [%#.x %#.0x]\n", 0, 0);
	ft_printf("- : [%#.x %#.0x]\n", 0, 0);
	printf("* : [%x]\n", 0);
	ft_printf("- : [%x]\n", 0);
	printf("* : [%#x]\n", 0);
	ft_printf("- : [%#x]\n", 0);
	printf("* : [%x] [%X]\n", 42, 42);
	ft_printf("- : [%x] [%X]\n", 42, 42);
	printf("* : [%x]\n", -15);
	ft_printf("- : [%x]\n", -15);
	printf("* : [%#08x]\n", 42);
	ft_printf("- : [%#08x]\n", 42);
	printf("* : [%5.2x]\n", 5142);
	ft_printf("- : [%5.2x]\n", 5142);
	printf("* : [%8x]\n", 42);
	ft_printf("- : [%8x]\n", 42);
	printf("* : [%#8x]\n", 42);
	ft_printf("- : [%#8x]\n", 42);
	printf("* : [%#-8x]\n", 42);
	ft_printf("- : [%#-8x]\n", 42);
	printf("* : [%ll#x]\n", 9223372036854775807);
	ft_printf("- : [%ll#x]\n", 9223372036854775807);
	printf("* : [%zx]\n", ULONG_MAX);
	ft_printf("- : [%zx]\n", ULONG_MAX);
	// ------------------------------------------------------------------------
	// ------------------------------------------ double test -----------------	
	printf("\n######## DOUBLE ########\n");
	printf("* : [%.1000lf]\n", 9999999999999999);
	ft_printf("- : [%.1000lf]\n", 9999999999999999);
	printf("* : [%f]\n", 1.42);
	ft_printf("- : [%f]\n", 1.42);
	printf("* : [% f]\n", 1.42);
	ft_printf("- : [% f]\n", 1.42);
	printf("* : [%0+f]\n", 1.42);
	ft_printf("- : [%0+f]\n", 1.42);
	printf("* : [%+f]\n", (double)-1.42);
	ft_printf("- : [%+f]\n", (double)-1.42);
	printf("* : [%+f]\n", -0.419990099999999992895);
	ft_printf("- : [%+f]\n", -0.419990099999999992895);
	printf("* : [%+f]\n", -0.42);
	ft_printf("- : [%+f]\n", -0.42);
	printf("* : [%.f]\n", -1.42);
	ft_printf("- : [%.f]\n", -1.42);
	printf("* : [%.f]\n", 1.42);
	ft_printf("- : [%.f]\n", 1.42);
	printf("* : [%1.f]\n", 1.42);
	ft_printf("- : [%1.f]\n", 1.42);
	printf("* : [%.10f]\n", 1.42);
	ft_printf("- : [%.10f]\n", 1.42);
	printf("* : [%15.10f]\n", 1.425687);
	ft_printf("- : [%15.10f]\n", 1.425687);
	printf("* : [%-15.10f]\n", 1.425687);
	ft_printf("- : [%-15.10f]\n", 1.425687);
	printf("* : [%-15.1f]\n", 7801.425687);
	ft_printf("- : [%-15.1f]\n", 7801.425687);
	printf("* : [%-15.100f]\n", 5671.425687);
	ft_printf("- : [%-15.100f]\n", 5671.425687);
	printf("* : [%-15.25f]\n", 5786671.425687);
	ft_printf("- : [%-15.25f]\n", 5786671.425687);
	printf("* : [%-15.25f]\n", ULLONG_MAX);
	ft_printf("- : [%-15.25f]\n", ULLONG_MAX);
	// ------------------------------------------------------------------------
	return (0);
}
