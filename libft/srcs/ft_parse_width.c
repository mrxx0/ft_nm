/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:45:47 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/24 11:36:38 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_parse_width(const char *str, t_arg *arg)
{
	int i;

	i = 0;
	if (*str == '*')
	{
		arg->min_width = -1;
		while (*(str + i) == '*')
			i++;
	}
	else if (*(str + i) >= '0' && *(str + i) <= '9')
	{
		arg->min_width = ft_atoi(str + i);
		while (*(str + i) >= '0' && *(str + i) <= '9')
			i++;
	}
	return (i);
}
