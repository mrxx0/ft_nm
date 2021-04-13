/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:12:10 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/04 16:12:44 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_type_octal(va_list ap, t_arg *arg)
{
	return (ft_unsigned(ap, arg, 8));
}

int		ft_type_unsigned(va_list ap, t_arg *arg)
{
	return (ft_unsigned(ap, arg, 10));
}

int		ft_type_hexmin(va_list ap, t_arg *arg)
{
	int i;

	i = ft_type_hexmaj(ap, arg);
	ft_strlower(arg->print);
	return (i);
}

int		ft_type_hexmaj(va_list ap, t_arg *arg)
{
	return (ft_unsigned(ap, arg, 16));
}
