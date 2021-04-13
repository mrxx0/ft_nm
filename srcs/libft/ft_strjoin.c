/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:16:29 by chcoutur          #+#    #+#             */
/*   Updated: 2019/04/25 14:30:04 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, char const *s2)
{
	char	*s_final;
	size_t	size;

	if (s1 && s2)
	{
		s_final = NULL;
		size = (ft_strlen(s1) + (ft_strlen(s2)));
		if (!(s_final = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		*(s_final + size) = '\0';
		ft_strcpy(s_final, s1);
		ft_strcat(s_final, s2);
		return (s_final);
	}
	return (0);
}
