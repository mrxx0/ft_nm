/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:05:14 by chcoutur          #+#    #+#             */
/*   Updated: 2018/11/26 09:59:59 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpy_src;
	unsigned char	*cpy_dst;

	i = 0;
	cpy_src = ((unsigned char*)src);
	cpy_dst = ((unsigned char*)dst);
	while (i < n)
	{
		cpy_dst[i] = cpy_src[i];
		if ((cpy_src)[i] == (unsigned char)c)
			return (cpy_dst + i + 1);
		i++;
	}
	return (NULL);
}
