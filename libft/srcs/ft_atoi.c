/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:59:24 by chcoutur          #+#    #+#             */
/*   Updated: 2018/12/10 09:44:01 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int			i;
	int			negative;
	long long	result;

	i = 0;
	negative = 0;
	result = 0;
	while ((str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
				|| str[i] == '\r' || str[i] == '\v'
				|| str[i] == ' ') && str[i] != 0)
		i++;
	if (str[i] == '-')
	{
		negative = 1;
		i++;
	}
	if (str[i] == '+' && str[i - 1] != '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (result < 0)
			return (negative ? 0 : -1);
	}
	return ((int)(negative ? -result : result));
}
