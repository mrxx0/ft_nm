/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sharp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:59:12 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/18 15:29:42 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_sharp(t_arg *arg)
{
	arg->old_print = NULL;
	if (ft_addflag(arg, SHARP))
	{
		if (arg->arg_type == 'o')
			arg->old_print = "0";
		else if (arg->arg_type == 'x')
			arg->old_print = "0x";
		else if (arg->arg_type == 'X')
			arg->old_print = "0X";
		arg->old_print_size = ft_strlen(arg->old_print);
		arg->old_print_size = ft_strlen(arg->old_print);
	}
	else
		arg->old_print_size = 0;
	return (1);
}
