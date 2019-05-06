/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:51:26 by lucmarti          #+#    #+#             */
/*   Updated: 2019/05/06 12:55:28 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_type(char c)
{
	int		i;
	char	*codex;

	codex = "%icpsfdouxXDOU";
	i = 0;
	while (codex[i] != '\0')
		if (codex[i++] == c)
			return (1);
	return (0);
}

int	is_mod(char c)
{
	int		i;
	char	*codex;

	codex = "Lhjlz";
	i = 0;
	if (c < codex[0] || c > codex[ft_strlen(codex)])
		return (0);
	while (codex[i] != '\0')
	{
		if (c < codex[i])
			return (0);
		if (c == codex[i])
			return (1);
		++i;
	}
	return (0);
}
