/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:50:26 by thallard          #+#    #+#             */
/*   Updated: 2020/11/23 15:54:15 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dest, int character, size_t len)
{
	char	*str;
	size_t	i;

	i = -1;
	str = (char *)dest;
	while (++i < len)
	{
		if (str[i] == (char)character)
			return ((void *)str + i);
	}
	return (NULL);
}
