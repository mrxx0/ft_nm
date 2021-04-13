/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:24:25 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/24 12:04:10 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	ft_width(t_arg *arg)
{
	char *str_new;

	if (arg->print_size >= arg->min_width)
		return (1);
	if (!(str_new = ft_strnew(arg->min_width)))
		return (0);
	if (ft_addflag(arg, LEFT_JUST))
	{
		ft_memcpy(str_new, arg->print, arg->print_size);
		ft_memset(str_new + arg->print_size, ' ',
				arg->min_width - arg->print_size);
	}
	else
	{
		ft_memset(str_new, ' ', arg->min_width - arg->print_size);
		ft_memcpy(str_new + (arg->min_width - arg->print_size),
				arg->print, arg->print_size);
	}
	free(arg->print);
	arg->print = str_new;
	arg->print_size = arg->min_width;
	return (1);
}

int			ft_type_pointer(va_list ap, t_arg *arg)
{
	char *tmp;

	if (!(arg->print = ft_strnew(14)))
		return (0);
	tmp = ft_ullitoa_base(va_arg(ap, unsigned long), 16);
	if (!(arg->print = ft_strjoin_free("0x", arg->print, 2)))
		return (0);
	if (tmp != 0 && arg->precision != -2)
		arg->print = ft_strjoin_free(arg->print, tmp, 1);
	ft_strlower(arg->print);
	free(tmp);
	arg->print_size = ft_strlen(arg->print);
	return (ft_width(arg));
}
