/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 08:12:38 by thallard          #+#    #+#             */
/*   Updated: 2020/12/14 14:48:31 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin_gnl(char *s1, char *s2, int f)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	if (!(res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[++j])
		res[++i] = s1[j];
	j = -1;
	while (s2[++j])
		res[++i] = s2[j];
	res[i + 1] = '\0';
	if (f)
		free(s1);
	return (res);
}
