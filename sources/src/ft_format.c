/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 10:58:23 by lucmarti          #+#    #+#             */
/*   Updated: 2019/03/06 11:16:30 by lucmarti         ###   ########.fr       */
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
	size += (arg->ef->fsize > arg->ef->pr ? arg->ef->fsize : arg->ef->pr);
	if (((char *)arg->data)[0] == '-')
		size += 1;
	//size += ft_strlen((char *)arg->data);
	//printf("Output size : %li\n", size);
	return (size);
}

static void ft_add_fc(char *out, char c, int n, int *i)
{
	//printf("n %i\ni %i\n", n, *i);
	//printf("%c\n", c);
	while (n > 0)
	{
		out[(*i)++] = c;
		--n;
	}
}

static void	ft_format_aux(char *out, t_arg *arg)
{
	t_eflag	*ef;
	int		sign;
	int		fsl;
	int		prl;
	int		signpos;

	int		i;
	int		l;

	signpos = 0;
	ef = arg->ef;
	sign = ef->positive;
	fsl = ef->fsize;
	prl = ef->pr;
	i = 0;
	l = 0;

	if (prl != 0)
		fsl = fsl - ft_strlen(arg->data);
	fsl = fsl - ft_strlen(arg->data);
	prl = ((int)(prl - ft_strlen(arg->data)) > 0 ? (prl - ft_strlen(arg->data)) : 0);
	if (ef->positive)
		fsl -= 1;
	if (((char *)(arg->data))[l] == '-')
		prl += 1;
	if ((arg->type == 2 || arg->type == 1) && (size_t)prl > ft_strlen(arg->data))
		prl = 0;//ft_strlen(arg->data);
	fsl = fsl - prl > 0 ? fsl - prl : 0;
	if ((arg->type == 2 || arg->type == 1) && (size_t)ef->pr > ft_strlen(arg->data))
		prl = ft_strlen(arg->data);
	else if ((size_t)ef->pr < ft_strlen(arg->data))
		prl = ef->pr;
	if (fsl != 0 || prl < fsl)
		signpos = fsl;
	if (arg->type == 4)
		prl = 0;
	/*printf("fsize     : %i\n", ef->fsize);
	printf("precision : %i\n", ef->pr);
	printf("fsl : %i\n", fsl);
	printf("prl : %i\n", prl);
	printf("fsl : %i\n", fsl);
	printf("prl : %i\n", prl);
	printf("signpos : %i\n", signpos);*/




	if (signpos == 0)
	{
		if (((char *)(arg->data))[l] == '-')
		{
			++l;
			ft_add_fc(out, '-', 1, &i);
		}
		else
			if (ef->positive != 0)
				ft_add_fc(out, sign, 1, &i);
	}
	if (ef->zero)
		ft_add_fc(out, '0', fsl, &i);
	else
		ft_add_fc(out, ' ', fsl, &i);
	if (i == signpos)
	{
		if (((char *)(arg->data))[l] == '-')
		{
			++l;
			ft_add_fc(out, '-', 1, &i);
		}
		else if (ef->positive)
			ft_add_fc(out, sign, 1, &i);
	}
	if (prl >= 0 && (arg->type == 0 || arg->type == 1)) 
	{
		if (ef->pr == 0 && ef->fsize == 0)
			prl = ft_strlen(arg->data);
		while (((char *)(arg->data))[l] != '\0' && prl > 0)
		{
			out[i++] = ((char *)(arg->data))[l];
			++l;
			--prl;
		}
	}
	else
	{
		ft_add_fc(out, '0', prl, &i);
		while (((char *)(arg->data))[l] != '\0')
		{
			out[i++] = ((char *)(arg->data))[l];
			++l;
		}
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
	ft_bzero(content, s);
	content[s - 1] = '\0';
	i = 0;
	ft_format_aux(content, arg);
	printf("Converted and formatted data :\n[%s]\n", content);
	return (content);
}

char	*ft_get_argx(t_arg *head, int index)
{
	while (index > 0 && head->next != NULL)
	{
		head = head->next;
		--index;	
	}
	if (head->type == 4)
	{
		if (head->ef->lalign == 0)
			ft_strjoin("", "");
	}
	else
	{
	}
	return (NULL);
}

char	*ft_sub_nc(const char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] != '\0' && str[i] != '%')
		++i;
	ret = ft_strsub(str, 0, i - 1);
	return (ret);
}

char	*ft_format_str(const char *str, t_arg *args)
{
	t_arg	*head;
	char	*out;

	(void)str;
	head = args;
	out = NULL;
	while (head != NULL)
	{
		if (head->type == 1)
			printf("[%s]\n", printf_string(head));
		else if (head->type == 3)
			printf("[%s]\n", printf_int(head));
		else
			ft_man_fs(head);
		head = head->next;
	}
	if (str[0] == '%')
		out = NULL;
	else
		out = ft_sub_nc(str);
	return (out);
}
