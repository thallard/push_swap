/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:13:02 by thallard          #+#    #+#             */
/*   Updated: 2020/11/23 16:13:03 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(res = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (*s)
	{
		res[i] = f(i, *s++);
		i++;
	}
	res[i] = '\0';
	return (res);
}
