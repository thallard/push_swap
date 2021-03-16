/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 02:09:29 by thallard          #+#    #+#             */
/*   Updated: 2020/11/23 15:32:27 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (!(dest) && !(src))
		return (dest);
	while (++i < len)
		((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}
