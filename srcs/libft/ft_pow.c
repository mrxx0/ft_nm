/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:17:43 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/13 10:18:05 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

long double	ft_pow(int nb, int power)
{
	long double nb1;

	nb1 = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power >= 2)
	{
		nb1 = nb * nb1;
		power--;
	}
	return (nb1);
}
