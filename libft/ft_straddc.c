/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:32:13 by lucmarti          #+#    #+#             */
/*   Updated: 2019/04/30 14:46:58 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddc(char c, char *src, char target)
{
	char	*out;
	int		i;
	int		l;

	i = 0;
	l = ft_strlen(src);
	if (!(out = malloc(sizeof(char) * (l + 2))))
		return (NULL);
	out[l + 1] = '\0';
	while (src[i] != '\0' && src[i] != target)
	{
		out[i] = src[i];
		++i;
	}
	if (src[i] == target)
	{
		out[i] = src[i];
		++i;
		out[i] = c;
		++i;
	}
	while (i < l + 1)
	{
		out[i] = src[i - 1];
		++i;
	}
	ft_memdel((void **)&src);
	return (out);
}
