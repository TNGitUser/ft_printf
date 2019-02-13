/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 09:46:40 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/13 13:09:01 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

int	main(void)
{
	char	*test;
	int		c;

	test = malloc(15);
	test[0] = '\0';
	strcat(test, "test");
	c = 105;
	ft_printf("Pointeur : %p\nContenu  : %-79ip\nChar 3   : %c\n", test, 4975, test[3]);
	printf("Pointeur : %p\nContenu  : %050i\nChar 3   : %c\n", test, 4975, test[3]);
	printf("------------\n\n");
	ft_memdel((void **)&test);
	return (0);
}
