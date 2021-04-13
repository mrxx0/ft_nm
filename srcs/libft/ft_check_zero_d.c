/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_zero_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:25:28 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/24 11:25:50 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check_zero_d(t_arg *arg)
{
	if (arg->flags == 0)
		return (ft_spec_zero_d(arg));
	else
		return (ft_spec_zero_d_flag(arg));
}
