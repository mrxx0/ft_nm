/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:05:37 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/24 12:03:43 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_shunt(t_arg *arg, int i, int l)
{
	if (ft_addflag(arg, ZERO) && l >= 2)
		ft_sp_wu_0(arg);
	else if ((ft_addflag(arg, ZERO) && l == 1) || i == 1)
		ft_sp_ws(arg);
	else if (i == arg->old_print_size)
		ft_sp_wu_0(arg);
	else if (i > arg->old_print_size)
		ft_sp_sup(arg, i);
	else if (arg->print[arg->print_size - 1] == ' ')
		ft_sp_lsp(arg);
	else if (i == 0 && l == 0)
		if (!(arg->print = ft_strjoin_free(arg->old_print, arg->print, 2)))
			return (0);
	return (1);
}

int			ft_sp_u(t_arg *arg)
{
	int i;
	int l;

	i = ft_rec_c(arg->print, ' ');
	l = ft_rec_c(arg->print, '0');
	if (*(arg->print + i) == '0' && arg->arg_type == 'o')
		return (1);
	if (ft_addflag(arg, SHARP))
	{
		if (arg->print_size == arg->min_width)
			ft_shunt(arg, i, l);
		else
		{
			if (!(arg->print = ft_strjoin_free(arg->old_print, arg->print, 2)))
				return (0);
		}
	}
	arg->print_size = ft_strlen(arg->print);
	return (1);
}
