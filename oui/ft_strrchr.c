/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:00:47 by thallard          #+#    #+#             */
/*   Updated: 2020/11/23 16:03:49 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int i;

	i = ft_strlen(string);
	while (i >= 0)
	{
		if (string[i] == (char)c)
			return ((char *)string + i);
		i--;
	}
	return (NULL);
}
