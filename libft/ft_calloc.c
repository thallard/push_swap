/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 01:52:37 by thallard          #+#    #+#             */
/*   Updated: 2020/11/23 15:52:14 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int len, int character)
{
	void	*ret;

	if (!(ret = malloc(len * character)))
		return (NULL);
	if (ret)
		ft_memset(ret, 0, len * character);
	return (ret);
}
