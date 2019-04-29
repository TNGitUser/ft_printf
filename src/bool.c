/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:51:26 by lucmarti          #+#    #+#             */
/*   Updated: 2019/04/29 10:53:17 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_type(char c)
{
	int		i;
	char	*codex;

	codex = "icpsfdouxX";
	i = 0;
	while (codex[i] != '\0')
		if (codex[i++] == c)
			return (1);
	return (0);
}
