/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 02:06:06 by thallard          #+#    #+#             */
/*   Updated: 2021/03/16 11:54:22 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *pointer, int size)
{
	int		i;

	i = -1;
	if (size == 0)
		return ;
	while (++i < size)
		((char *)pointer)[i] = '\0';
}
