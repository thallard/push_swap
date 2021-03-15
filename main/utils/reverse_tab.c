/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:01:42 by thallard          #+#    #+#             */
/*   Updated: 2021/03/15 13:27:16 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		reverse_tab(t_global *g)
{
	int		i;
	int		j;

	j = len(g->a_temp);
	i = -1;
	if (!(g->a = malloc_lst(sizeof(char *) * (j + 2), g)))
		ft_exit(g);
	while (--j >= 0)
		g->a[++i] = g->a_temp[j];
	g->a[++i] = NULL;
	return (1);
}