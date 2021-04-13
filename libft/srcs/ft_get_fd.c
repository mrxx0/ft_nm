/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:47:07 by chcoutur          #+#    #+#             */
/*   Updated: 2019/09/23 16:51:26 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

char	*ft_get_fd(int fd)
{
	char	*line;
	int		res;

	while ((res = get_next_line(fd, &line)) > 0)
		return (line);
	return (NULL);
}
