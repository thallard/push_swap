/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:04:03 by thallard          #+#    #+#             */
/*   Updated: 2020/11/23 16:04:06 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, int len)
{
	int		i;
	int		k;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		k = 0;
		while (str[i + k] == to_find[k] && i + k < len)
			if (to_find[k++ + 1] == '\0')
				return ((char *)str + i);
		i++;
	}
	return (0);
}
