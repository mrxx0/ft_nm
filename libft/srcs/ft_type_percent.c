/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:23:37 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/04 16:24:11 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_type_percent(va_list ap, t_arg *arg)
{
	int i;

	i = 0;
	(void)ap;
	arg->print_size = arg->min_width > 0 ? arg->min_width : 1;
	if (!(arg->print = malloc(arg->print_size)))
		return (-1);
	ft_memset(arg->print, ' ', arg->print_size);
	*(arg->print + (ft_addflag(arg, LEFT_JUST) ? 0 :
				arg->print_size - 1)) = '%';
	while (ft_addflag(arg, ZERO) && *(arg->print + i) == ' ')
		*(arg->print + i++) = '0';
	return (1);
}
