/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:53:52 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/18 15:27:50 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_free_arg(char **tab_mant, char *str)
{
	int i;

	i = 0;
	while (tab_mant[i])
	{
		ft_strdel(&tab_mant[i]);
		i++;
	}
	free(tab_mant);
	ft_strdel(&str);
}
