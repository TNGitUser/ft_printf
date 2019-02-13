/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ext.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:49:54 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/13 10:05:28 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_a_init(t_ext *ext, size_t n)
{
	size_t c;

	c = 0;
	while (c < n)
	{
		ext->pr[c] = 0;
		ext->fs[c] = 0;
		ext->prefix[c] = 0;
		ext->pads[c] = 0;
		ext->sign[c] = -2;
		++c;
	}
}

void		ft_init_ext(t_pargs *args)
{
	t_ext	*ext;

	if (!(ext = malloc(sizeof(t_ext))))
		exit(1);
	if (!(ext->pr = malloc(sizeof(int) * (args->cvn))))
		exit(1);
	if (!(ext->fs = malloc(sizeof(int) * (args->cvn))))
		exit(1);
	if (!(ext->prefix = malloc(sizeof(int) * (args->cvn))))
		exit(1);
	if (!(ext->pads = malloc(sizeof(int) * (args->cvn))))
		exit(1);
	if (!(ext->sign = malloc(sizeof(int) * (args->cvn))))
		exit(1);
	ft_a_init(ext, args->cvn);
	args->ext = ext;
}

void		ft_free_ext(t_ext *ext)
{
	ft_memdel((void**)&(ext->pr));
	ft_memdel((void**)&(ext->fs));
	ft_memdel((void**)&(ext->prefix));
	ft_memdel((void**)&(ext->pads));
	ft_memdel((void**)&(ext->sign));
	ft_memdel((void**)&ext);
}

void		ft_set_ext(t_pargs *args, int c, const char *str, int len)
{
	char	*cv;
	char	*sub;
	int		i;
	int		u;

	u = 0;
	cv = ft_strsub(str, 0, len);
	printf("'%s'\n", cv);
	i = 0;
	while (cv[i] != '\0')
	{
		if (cv[i] == '0' && i == 0)
		{
			args->ext->prefix[c] = -1;
			if (cv[i + 1] <= '9' && cv[i + 1] >= '0')
				ft_set_fs(args, c, ft_atoi((str + i), &i));
		}
		if (cv[i] == '+' || cv[i] == '-' || cv[i] == ' ')
		{
			if (str[i] == '+')
				args->ext->sign[c] = 1;
			else
				args->ext->sign[c] = str[i] == '-' ? -1 : 0;
		}
		if (cv[i] <= '9' && cv[i] >= '0')
		{
			u = i;
			while (cv[u] <= '9' && cv[u] >= '0')
				++u;
			sub = ft_strsub(cv, i, u - i);
			i = u - 1;
			ft_set_fs(args, c, ft_atoi(sub, &u));
			ft_memdel((void **)&sub);
		}
		++i;
	}
	ft_memdel((void **)&cv);
	/*while (i < len && str[i] != '\0' && !ft_is_cflag(str[i]))
	{
		if (str[i] == '0' && i == 0)
		{
			args->ext->prefix[c] = -1;
			ft_set_fs(args, c, ft_atoi((char *)(str + i + 1), &i));
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == ' ')
		{
			if (str[i] == '+')
				args->ext->sign[c] = 1;
			else
				args->ext->sign[c] = str[i] == '-' ? -1 : 0;
			++i;
		}
		if (str[i] == '.')
			args->ext->pr[c] = ft_atoi((char *)(str + i + 1), &i);
		else if (str[i] <= '9' && str[i] >= '1')
			ft_set_fs(args, c, ft_atoi((char *)(str + i), &i));
		++i;
	}*/
}
