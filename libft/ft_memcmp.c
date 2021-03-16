/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:35:52 by thallard          #+#    #+#             */
/*   Updated: 2020/11/23 15:35:53 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *dest, const void *source, size_t len)
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			i;

	dst = (unsigned char *)dest;
	src = (unsigned char *)source;
	i = -1;
	while (++i < len)
		if (dst[i] != src[i])
			return (dst[i] - src[i]);
	return (0);
}
