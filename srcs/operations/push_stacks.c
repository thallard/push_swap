/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:54:22 by thallard          #+#    #+#             */
/*   Updated: 2021/03/03 17:41:48 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int		swap_a(t_global *g)
{
	char	*tmp;

	if (get_tab_length(g->a) >= 2)
	{
		tmp = g->a[get_tab_length(g->a) - 2];
		g->a[get_tab_length(g->a) - 2] = g->a[get_tab_length(g->a) - 1];
		g->a[get_tab_length(g->a) - 1] = tmp;
	}
	print_stack(g);
	return (1);
}

int		swap_b(t_global *g)
{
	
}