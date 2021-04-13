/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:37:30 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/13 10:56:14 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_parse_precision(const char *str, t_arg *arg)
{
	int i;

	i = 1;
	if (*(str) != '.')
		return (0);
	if (*(str + i) == '*')
	{
		arg->precision = -1;
		while (*(str + i) == '*')
			i++;
		return (i);
	}
	else if (*(str + i) >= '0' && *(str + i) <= '9')
	{
		arg->precision = ft_atoi(str + i);
		while (*(str + i) >= '0' && *(str + i) <= '9')
			i++;
		if (arg->precision == 0)
			arg->precision = -2;
	}
	else
		arg->precision = -2;
	return (i);
}
