/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:53:17 by thallard          #+#    #+#             */
/*   Updated: 2020/11/23 15:53:24 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void *src, int character, size_t len)
{
	unsigned int	i;
	char			*dst;
	char			*str;
	char			*ptr;

	dst = (char *)dest;
	str = (char *)src;
	i = -1;
	ptr = 0;
	while (++i < len && ptr == 0)
	{
		dst[i] = str[i];
		if (str[i] == ((char)character))
			ptr = dst + i + 1;
	}
	return (ptr);
}
