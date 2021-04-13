/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:19:44 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/13 10:20:05 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strlower(char *str)
{
	char	*dst;
	int		i;

	dst = str;
	i = 0;
	while (dst[i])
	{
		dst[i] = ft_tolower(dst[i]);
		i++;
	}
	return (dst);
}
