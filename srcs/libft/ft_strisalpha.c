/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:18:36 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/13 10:19:35 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strisalpha(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	else
	{
		i = 0;
		while (str[i])
		{
			if (ft_isalpha(str[i]))
				i++;
			else
				return (0);
		}
	}
	return (1);
}
