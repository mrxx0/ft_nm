/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:15:00 by chcoutur          #+#    #+#             */
/*   Updated: 2018/12/10 09:46:45 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src >= dst)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len)
		{
			((char*)dst)[len - 1] = ((char*)src)[len - 1];
			len--;
		}
	}
	return (dst);
}
