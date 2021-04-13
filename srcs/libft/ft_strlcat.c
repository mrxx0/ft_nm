/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:28:56 by chcoutur          #+#    #+#             */
/*   Updated: 2018/12/10 09:54:18 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;

	len_dst = ft_strlen(dst);
	if (size <= len_dst)
		return (ft_strlen(src) + size);
	else
	{
		ft_strncat(dst, src, (size - len_dst - 1));
		return (ft_strlen(src) + len_dst);
	}
}
