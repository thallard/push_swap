/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:15:41 by thallard          #+#    #+#             */
/*   Updated: 2021/03/13 13:59:57 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

int     mini_algo(t_global *g)
{
    push_b(g);
    push_b(g);

	if (len(g->a) >= 2 && ft_atoi(g->a[len(g->a) - 1]) > ft_atoi(g->a[len(g->a) - 2]))
		swap_a(g);
	if (ft_atoi(g->a[1]) > ft_atoi(g->a[0]))
	{
		swap_a(g);
		rotate_a(g);
	}
	if (len(g->a) >= 2 && ft_atoi(g->a[len(g->a) - 1]) > ft_atoi(g->a[len(g->a) - 2]))
		swap_a(g);
	if (ft_atoi(g->b[0]) == g->min[g->size - 2] && ft_atoi(g->b[1]) == g->min[g->size - 3])
	{
		reverse_rotate_a(g);
		swap_b(g);
		push_a(g);
		push_a(g);
		rotate_a(g);
		rotate_a(g);
		rotate_a(g);
	}
	push_a(g);
	if (len(g->a) == 4 && ft_atoi(g->a[len(g->a) - 1]) == g->min[g->size - 3] &&
		ft_atoi(g->a[1]) == g->min[1])
{
		dprintf(1, "oui\n");
		swap_a(g);
		rotate_a(g);
		swap_a(g);
		reverse_rotate_a(g);
}
	if (ft_atoi(g->a[len(g->a) - 1]) == g->min[g->size - 2]&& len(g->a) >= 4)
	{
		reverse_rotate_a(g);
		swap_a(g);
		rotate_a(g);
		rotate_a(g);
	}
		if (ft_atoi(g->a[len(g->a) - 1]) == g->min[g->size - 3]&& len(g->a) >= 5)
	{
		swap_a(g);
		dprintf(1, "debug ici\n");
		reverse_rotate_a(g);
		swap_a(g);
		rotate_a(g);
	}
	if (is_max(g, g->a, ft_atoi(g->a[len(g->a) - 1])))
		rotate_a(g);
		if (len(g->a) >= 2 && ft_atoi(g->a[len(g->a) - 1]) > ft_atoi(g->a[len(g->a) - 2]))
		swap_a(g);
	push_a(g);
		if (ft_atoi(g->a[len(g->a) - 1]) == g->min[g->size - 2] && len(g->a) >= 4)
	{
		reverse_rotate_a(g);
		swap_a(g);
		rotate_a(g);
		rotate_a(g);
	}
	if (ft_atoi(g->a[len(g->a) - 1]) == g->min[g->size - 3] && len(g->a) >= 5)
	{
		swap_a(g);
		dprintf(1, "debug ici\n");
		rotate_a(g);
			swap_a(g);
		reverse_rotate_a(g);
	}
	if (is_max(g, g->a, ft_atoi(g->a[len(g->a) - 1])))
		rotate_a(g);
	if (len(g->a) >= 2 && ft_atoi(g->a[len(g->a) - 1]) > ft_atoi(g->a[len(g->a) - 2]))
		swap_a(g);

    return (1);
}