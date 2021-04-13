/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:12:06 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/13 10:12:34 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_free_str(char *str)
{
	char *str_ret;

	str_ret = NULL;
	str_ret = str;
	free(str);
	return (str_ret);
}
