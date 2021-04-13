/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:37:51 by chcoutur          #+#    #+#             */
/*   Updated: 2019/03/04 18:19:00 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s_cpy;

	i = 0;
	j = start;
	s_cpy = NULL;
	if (s)
	{
		if (!(s_cpy = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			s_cpy[i] = s[j];
			i++;
			j++;
		}
		s_cpy[i] = '\0';
		return (s_cpy);
	}
	return (NULL);
}
