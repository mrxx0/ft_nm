/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:39:49 by chcoutur          #+#    #+#             */
/*   Updated: 2019/06/18 15:29:32 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_not_p(char str, int len)
{
	write(1, &str, 1);
	len++;
	return (len);
}

int			ft_printf(const char *str, ...)
{
	int		len;
	int		ret;
	t_arg	*arg;
	va_list	ap;

	len = 0;
	va_start(ap, str);
	if (str)
	{
		while (*str != '\0')
		{
			if (*str == '%')
			{
				if (!(ret = ft_parsing(str, &arg)))
					return (-1);
				str += ret;
				len += ft_dis(arg, ap);
				free(arg);
			}
			else
				len = ft_not_p(*str++, len);
		}
	}
	va_end(ap);
	return (len);
}
