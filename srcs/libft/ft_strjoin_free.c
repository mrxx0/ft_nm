/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:07:43 by chcoutur          #+#    #+#             */
/*   Updated: 2018/12/10 09:53:51 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int i)
{
	char *tmp;

	if (s1 && s2)
	{
		tmp = ft_strjoin(s1, s2);
		if (i == 1)
			free(s1);
		else if (i == 2)
			free(s2);
		else if (i == 3)
		{
			free(s1);
			free(s2);
		}
		return (tmp);
	}
	return (0);
}
