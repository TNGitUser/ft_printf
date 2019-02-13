/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:09:56 by lucmarti          #+#    #+#             */
/*   Updated: 2018/11/12 09:55:58 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char *cdst;

	cdst = dst;
	while (*src != '\0')
	{
		*cdst = *src;
		++cdst;
		++src;
	}
	*cdst = '\0';
	return (dst);
}
