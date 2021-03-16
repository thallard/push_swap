/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:53:44 by thallard          #+#    #+#             */
/*   Updated: 2020/11/25 14:09:46 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*s;
	unsigned char		*d;
	size_t				i;

	if (!(dest) && !(src))
		return (NULL);
	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (d < s)
		while (len-- > 0)
		{
			d[i] = s[i];
			i++;
		}
	else
		while (len-- > 0)
			d[len] = s[len];
	return (dest);
}
