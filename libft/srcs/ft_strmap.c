/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 08:58:48 by chcoutur          #+#    #+#             */
/*   Updated: 2018/12/10 09:54:48 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s_cpy;

	i = 0;
	s_cpy = NULL;
	if (s && f)
	{
		if (!(s_cpy = ft_strdup(s)))
			return (NULL);
		while (s[i])
		{
			s_cpy[i] = f(s[i]);
			i++;
		}
		s_cpy[i] = '\0';
	}
	return (s_cpy);
}
