/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:58:06 by thallard          #+#    #+#             */
/*   Updated: 2020/11/23 15:58:46 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char				c;
	unsigned int		i;

	if (!dest || !src)
		return (0);
	c = *src;
	i = 0;
	if (size == 0)
		return ((unsigned int)ft_strlen(src));
	else
	{
		while (c && (i < size - 1))
		{
			*(dest + i++) = c;
			c = *(src + i);
		}
		*(dest + i) = '\0';
		return ((unsigned int)ft_strlen(src));
	}
}
