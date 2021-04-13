/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:48:01 by chcoutur          #+#    #+#             */
/*   Updated: 2018/12/10 09:58:02 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	char		*s_cpy;

	if (s)
	{
		i = 0;
		j = ft_strlen(s) - 1;
		s_cpy = NULL;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (s[i] == '\0')
			return (ft_strnew(1));
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		s_cpy = ft_strsub(s, i, j - i + 1);
		return (s_cpy);
	}
	return (NULL);
}
