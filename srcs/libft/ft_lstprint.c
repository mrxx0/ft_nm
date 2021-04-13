/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:09:18 by qbenaroc          #+#    #+#             */
/*   Updated: 2018/11/17 15:29:58 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *alst)
{
	while (alst)
	{
		ft_putstr((char*)(alst->content));
		ft_putstr(" / ");
		ft_putnbr((int)alst->content_size);
		ft_putstr("\t->\t");
		alst = alst->next;
	}
	ft_putstr("NULL");
}
