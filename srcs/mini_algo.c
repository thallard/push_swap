/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:15:41 by thallard          #+#    #+#             */
/*   Updated: 2021/03/13 15:37:50 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

int		solve_cas(t_global *g)
{
	if (ft_atoi(g->b[1]) == g->min[g->size - 2] &&
		ft_atoi(g->b[0]) == g->min[g->size - 3] &&
		ft_atoi(g->a[0]) == g->min[g->size - 1])
	{
		reverse_rotate_a(g);
		push_a(g);
		push_a(g);
		rotate_a(g);
		rotate_a(g);
		rotate_a(g);
		return (1);
	}
	return (0);
}

int		prepare_stack_a(t_global *g)
{
	if (len(g->a) >= 2 && ft_atoi(g->a[len(g->a) - 1]) >
		ft_atoi(g->a[len(g->a) - 2]))
		swap_a(g);

	if (ft_atoi(g->a[1]) >
		ft_atoi(g->a[0]) && !is_max(g, g->a, ft_atoi(g->a[len(g->a) - 1])))
		reverse_rotate_a(g);
	if (len(g->a) >= 2 && ft_atoi(g->a[len(g->a) - 1]) >
		ft_atoi(g->a[len(g->a) - 2]))
		swap_a(g);
	if (solve_cas(g))
		return (1);
	if (ft_atoi(g->b[0]) == g->min[g->size - 2]
		&& ft_atoi(g->b[1]) == g->min[g->size - 3])
	{
		reverse_rotate_a(g);
		swap_b(g);
		push_a(g);
		push_a(g);
		rotate_a(g);
		rotate_a(g);
		rotate_a(g);
	}
	return (1);
}

void	push_a_and_sort(t_global *g)
{
	push_a(g);
	if (is_max(g, g->a, ft_atoi(g->a[len(g->a) - 1]))
		&& ft_atoi(g->b[0]) == g->min[g->size - 1])
		rotate_a(g);
	if (len(g->a) == 4 && ft_atoi(g->a[len(g->a) - 1]) == g->min[g->size - 3] &&
		ft_atoi(g->a[1]) == g->min[1] &&  len(g->a) >= 4)
	{
				dprintf(1, "ici\n");
		swap_a(g);
		rotate_a(g);
		swap_a(g);
		reverse_rotate_a(g);
	}
	if (ft_atoi(g->a[len(g->a) - 1]) == g->min[g->size - 2] && len(g->a) >= 4)
	{
		dprintf(1, "ici\n");
		reverse_rotate_a(g);
		swap_a(g);
		rotate_a(g);
		rotate_a(g);
	}
	if (ft_atoi(g->a[len(g->a) - 1]) == g->min[g->size - 3] && len(g->a) >= 5)
	{
		dprintf(1, "ouioui\n");
		swap_a(g);
		reverse_rotate_a(g);
		swap_a(g);
		rotate_a(g);
	}
	
}

void	finish_sort_a(t_global *g)
{
	if (ft_atoi(g->a[len(g->a) - 1]) == g->min[g->size - 2]
		&& len(g->a) >= 4)
	{
				dprintf(1, "ouioui\n");
		reverse_rotate_a(g);
		swap_a(g);
		rotate_a(g);
		rotate_a(g);
	}
	if (ft_atoi(g->a[len(g->a) - 1]) == g->min[g->size - 3] && len(g->a) >= 5)
	{
				dprintf(1, "ouioui\n");
		swap_a(g);
		rotate_a(g);
		swap_a(g);
		reverse_rotate_a(g);
	}
	if (is_max(g, g->a, ft_atoi(g->a[len(g->a) - 1])))
		rotate_a(g);
	if (len(g->a) >= 2 && ft_atoi(g->a[len(g->a) - 1])
		> ft_atoi(g->a[len(g->a) - 2]))
		swap_a(g);
}

int		mini_algo(t_global *g)
{
	push_b(g);
	push_b(g);
	prepare_stack_a(g);
	push_a_and_sort(g);
	if (is_max(g, g->a, ft_atoi(g->a[len(g->a) - 1])))
			rotate_a(g);
	if (len(g->a) >= 2 && ft_atoi(g->a[len(g->a) - 1])
		> ft_atoi(g->a[len(g->a) - 2]))
		{
			dprintf(1, "iciewq");
				swap_a(g);
		}
	
	push_a(g);
	finish_sort_a(g);
	return (1);
}
