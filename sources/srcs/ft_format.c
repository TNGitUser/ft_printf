/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 10:58:23 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/18 13:41:12 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_compute_size(t_arg *arg)
{
	size_t	size;

	size = 0;
	if ((arg->type == 3 || arg->type == 4) &&
			arg->ef->positive != 0 && arg->str[0] != '-')
		size += 1;
	size += arg->ef->fsize > arg->ef->pr ? arg->ef->fsize : arg->ef->pr;
	size += ft_strlen((char *)arg->data);
	printf("Output size : %li\n", size);
	return (size);
}

static void	ft_ffirst_part(char *out, t_arg *arg, int *i)
{
	t_eflag		*ef;
	int			c;
	int			l;

	ef = arg->ef;
	l = 0;
	if (((char *)(arg->data))[l] == '-')
	{
		++l;
		out[(*i)++] = '-';
	}
	if (ef->lalign == 0 && ef->fsize != 0 && arg->type != 4)
	{
		c = ef->fsize - ef->pr;
		while (c > 0)
		{
			out[(*i)++] = ef->zero == 1 ? '0' : ' ';
			--c;
		}
	}
	if (arg->ef->positive != 0 && (arg->type == 3 || arg->type == 4))
			out[(*i)++] = arg->ef->positive == 1 ? '+' : ' ';
	while (((char *)(arg->data))[l] != '\0')
	{
		out[(*i)++] = ((char *)(arg->data))[l];
		++l;
	}
}

static char	*ft_man_fs(t_arg *arg)
{
	int		i;
	size_t	s;
	char	*content;
	
	s = ft_compute_size(arg) + 1;
	content = NULL;
	if (!(content = malloc(sizeof(char) * s)))
		exit(1);
	content[s] = '\0';
	i = 0;
	ft_ffirst_part(content, arg, &i);
	printf("Converted and formatted data : %s\n", content);
}

char	*ft_get_argx(t_arg *head, int index)
{
	while (index > 0 && head->next != NULL)
	{
		head = head->next;
		--index;	
	}
	if (head->type == 5)
	{
		if (head->ef->lalign == 0)
			ft_strjoin("", "");
	}
	else
	{
	}
	return (NULL);
}

char	*ft_sub_nc(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' || str[i] != '%')
		++i;
	return (ft_strsub(str, 0, i - 1));
}

char	*ft_format_str(char *str, t_arg *args)
{
	t_arg	*head;
	char	*out;

	head = args;
	out = NULL;
	while (head != NULL)
	{
		ft_man_fs(head);
		head = head->next;
	}
	/*if (str[0] == '%')
	  out = NULL;
	  else
	  out = ft_sub_nc(str);*/
	return (out);
}
