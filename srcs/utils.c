/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:04:25 by thallard          #+#    #+#             */
/*   Updated: 2021/03/03 16:27:20 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

void	print_stack(t_global *g)
{
	int		i;

	i = -1;
	while (g->a[++i])
	{
		printf("%s\n", g->a[i]);
	}
}