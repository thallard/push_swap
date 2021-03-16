/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:17:11 by thallard          #+#    #+#             */
/*   Updated: 2020/12/14 17:05:41 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_get_len(long n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0 && len == 0)
		n = n * (-1);
	while (n >= 1 && len++ >= 0)
		n /= 10;
	return (len);
}

void	ft_tolower_entire(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
}
