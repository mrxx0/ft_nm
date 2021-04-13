/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:42:20 by chcoutur          #+#    #+#             */
/*   Updated: 2018/12/10 09:56:25 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = ft_strlen(needle);
	j = 0;
	if (size == 0)
		return ((char *)haystack);
	while (haystack[j] && j < len)
	{
		i = 0;
		while (haystack[j + i] == needle[i] && (i + j) < len)
		{
			i++;
			if (!needle[i])
				return ((char *)&haystack[j]);
		}
		j++;
	}
	return (NULL);
}
