/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:32:52 by thallard          #+#    #+#             */
/*   Updated: 2020/11/23 16:47:18 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	if (!s)
	{
		write(fd, "\n", 1);
		return ;
	}
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
