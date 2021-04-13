/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:20:27 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/13 10:22:15 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_nblen(unsigned long long nb, int base)
{
	if (nb == 0)
		return (1);
	else if (nb / base > 0)
		return (1 + ft_nblen(nb / base, base));
	else
		return (1);
}

char			*ft_ullitoa_base(unsigned long long nb, int base)
{
	char	*str;
	size_t	len;

	len = ft_nblen(nb, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len-- > 0)
	{
		*(str + len) = (nb % base) + ((nb % base > 9) ? 'A' - 10 : '0');
		nb /= base;
	}
	return (str);
}
