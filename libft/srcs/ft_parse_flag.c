/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:32:22 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/18 15:28:39 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_addflag(t_arg *arg, int flag)
{
	return (arg->flags & flag);
}

int				ft_parse_flag(const char *str, t_arg *arg)
{
	int i;

	i = 0;
	while ((*(str + i)) == '-' || (*(str + i)) == '+' || (*(str + i) == '#')
			|| (*(str + i) == '0') || (*(str + i)) == ' ')
	{
		if (*(str + i) == '-')
			arg->flags |= LEFT_JUST;
		else if (*(str + i) == '+')
			arg->flags |= SIGN;
		else if (*(str + i) == '#')
			arg->flags |= SHARP;
		else if (*(str + i) == '0')
			arg->flags |= ZERO;
		else if (*(str + i) == ' ')
			arg->flags |= SPACE;
		i++;
	}
	return (i);
}
