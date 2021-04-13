/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:21:10 by chcoutur          #+#    #+#             */
/*   Updated: 2018/11/26 10:06:42 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int pos;
	int len;

	i = 0;
	pos = 0;
	len = ft_strlen(needle);
	if (len == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (needle[pos] == haystack[i + pos])
		{
			if (pos == len - 1)
				return ((char *)haystack + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (0);
}
