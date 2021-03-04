/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap_stacks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:54:22 by thallard          #+#    #+#             */
/*   Updated: 2021/03/04 14:17:43 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"


int		push_a(t_global *g)
{
	int		size_a;

	if (get_tab_length(g->b) >= 1)
	{
		size_a = get_tab_length(g->a);
		g->a[size_a] = g->b[get_tab_length(g->b) - 1];
		g->a[size_a + 1] = NULL;
		g->b[get_tab_length(g->b) - 1] = NULL;
	}
	print_stacks(g);
	return (1);
}

int		push_b(t_global *g)
{
	int		size_b;

	if (get_tab_length(g->a) >= 1)
	{
	
		size_b = get_tab_length(g->b);
		g->b[size_b] = g->a[get_tab_length(g->a) - 1];
		g->b[size_b + 1] = NULL;
	
		g->a[get_tab_length(g->a) - 1] = NULL;
	}
	print_stacks(g);
	return (1);
}

int		swap_a(t_global *g)
{
	char	*tmp;

	if (get_tab_length(g->a) >= 2)
	{
		tmp = g->a[get_tab_length(g->a) - 2];
		g->a[get_tab_length(g->a) - 2] = g->a[get_tab_length(g->a) - 1];
		g->a[get_tab_length(g->a) - 1] = tmp;
	}
	print_stacks(g);
	return (1);
}

int		swap_b(t_global *g)
{
	char	*tmp;

	if (get_tab_length(g->b) >= 2)
	{
		tmp = g->b[get_tab_length(g->b) - 2];
		g->b[get_tab_length(g->b) - 2] = g->b[get_tab_length(g->b) - 1];
		g->b[get_tab_length(g->b) - 1] = tmp;
	}
	print_stacks(g);
	return (1);
}

int		swap_ab(t_global *g)
{
	(void)g;
	return (1);
}