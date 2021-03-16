/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap_stacks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:54:22 by thallard          #+#    #+#             */
/*   Updated: 2021/03/16 10:16:10 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		push_a(t_global *g)
{
	int		size_a;

	if (len(g->b) >= 1)
	{
		size_a = len(g->a);
		g->a[size_a] = g->b[len(g->b) - 1];
		g->a[size_a + 1] = NULL;
		g->b[len(g->b) - 1] = NULL;
		g->coups++;
	}
	else
		return (0);
	if (!(g->action = ft_strdup("pa")) || !add_lst_to_free(g, g->action))
		ft_exit(g, 1);
	print_stacks(g);
	return (1);
}

int		push_b(t_global *g)
{
	int		size_b;

	if (len(g->a) >= 1)
	{
		size_b = len(g->b);
		g->b[size_b] = g->a[len(g->a) - 1];
		g->b[size_b + 1] = NULL;
		g->a[len(g->a) - 1] = NULL;
		g->coups++;
	}
	else
		return (0);
	if (!(g->action = ft_strdup("pb")) || !add_lst_to_free(g, g->action))
		ft_exit(g, 1);
	print_stacks(g);
	return (1);
}

int		swap_a(t_global *g)
{
	char	*tmp;

	if (len(g->a) >= 2)
	{
		tmp = g->a[len(g->a) - 2];
		g->a[len(g->a) - 2] = g->a[len(g->a) - 1];
		g->a[len(g->a) - 1] = tmp;
	}
	else
		return (0);
	if (!g->action || ft_strncmp(g->action, "ss", 3))
	{
		if (!(g->action = ft_strdup("sa")) || !add_lst_to_free(g, g->action))
			ft_exit(g, 1);
		g->coups++;
		print_stacks(g);
	}
	return (1);
}

int		swap_b(t_global *g)
{
	char	*tmp;

	if (len(g->b) >= 2)
	{
		tmp = g->b[len(g->b) - 2];
		g->b[len(g->b) - 2] = g->b[len(g->b) - 1];
		g->b[len(g->b) - 1] = tmp;
	}
	else
		return (0);
	if (!g->action || ft_strncmp(g->action, "ss", 3))
	{
		if (!(g->action = ft_strdup("sb")) || !add_lst_to_free(g, g->action))
			ft_exit(g, 1);
		g->coups++;
		print_stacks(g);
	}
	return (1);
}

int		swap_both(t_global *g)
{
	if (len(g->b) >= 2 && len(g->a) >= 2)
	{
		if (!(g->action = ft_strdup("ss")) || !add_lst_to_free(g, g->action))
			ft_exit(g, 1);
		swap_b(g);
		swap_a(g);
		g->coups++;
	}
	else
		return (0);
	print_stacks(g);
	return (1);
}
