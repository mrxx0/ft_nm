/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:59:39 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/24 12:03:05 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_space_float(t_arg *arg, int sign, int i)
{
	char	*str;

	i = ft_rec_c(arg->print, '0');
	if (ft_addflag(arg, SPACE) && sign == 0 && *arg->print != ' ')
	{
		if (arg->min_width == arg->print_size && ft_addflag(arg, ZERO)
				&& i >= 2)
			*arg->print = ' ';
		else if (arg->min_width == arg->print_size
				&& ft_addflag(arg, LEFT_JUST)
				&& arg->print[arg->print_size - 1] == ' ')
		{
			if (!(str = ft_strnew(arg->print_size)))
				return (0);
			ft_memset(str, ' ', arg->print_size);
			*str = ' ';
			ft_memcpy(str + 1, arg->print, arg->print_size - 1);
			free(arg->print);
			arg->print = str;
		}
		else
			arg->print = ft_strjoin_free(" ", arg->print, 2);
		arg->print_size = ft_strlen(arg->print);
	}
	return (1);
}
