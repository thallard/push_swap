/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:36:34 by thallard          #+#    #+#             */
/*   Updated: 2020/11/23 16:36:36 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	if (!(res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1)
		res[++i] = *s1++;
	while (*s2)
		res[++i] = *s2++;
	res[i + 1] = '\0';
	return (res);
}
