/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:17:24 by thallard          #+#    #+#             */
/*   Updated: 2021/03/15 14:46:06 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		rotate_a(t_global *g)
{
	char	*first;
	char	*tmp;
	int		i;

	if ((i = len(g->a)) < 1)
		return (-1);
	i = len(g->a) - 1;
	first = g->a[i];
	while (i > 0)
	{
		tmp = g->a[i];
		g->a[i] = g->a[i - 1];
		g->a[i - 1] = tmp;
		i--;
	}
	g->a[0] = first;
	if (!g->action || ft_strncmp(g->action, "rr", 3))
	{
		if (!(g->action = ft_strdup("ra")) || !add_lst_to_free(g, g->action))
			ft_exit(g);
		g->coups++;
		print_stacks(g);
	}
	return (1);
}

int		rotate_b(t_global *g)
{
	char	*first;
	char	*tmp;
	int		i;

	if (len(g->b) < 1)
		return (-1);
	i = len(g->b) - 1;
	first = g->b[i];
	while (i > 0)
	{
		tmp = g->b[i];
		g->b[i] = g->b[i - 1];
		g->b[i - 1] = tmp;
		i--;
	}
	g->b[0] = first;
	if (!g->action || ft_strncmp(g->action, "rr", 3))
	{
		if (!(g->action = ft_strdup("rb")) || !add_lst_to_free(g, g->action))
			ft_exit(g);
		g->coups++;
		print_stacks(g);
	}
	return (1);
}

int		reverse_rotate_b(t_global *g)
{
	char	*last;
	char	*tmp;
	int		i;

	if (len(g->b) < 1)
		return (-1);
	i = 0;
	last = g->b[i];
	while (i < len(g->b) - 1)
	{
		tmp = g->b[i];
		g->b[i] = g->b[i + 1];
		g->b[i + 1] = tmp;
		i++;
	}
	g->b[len(g->b) - 1] = last;
	if (!g->action || ft_strncmp(g->action, "rrr", 4))
	{
		if (!(g->action = ft_strdup("rrb")) || !add_lst_to_free(g, g->action))
			ft_exit(g);
		g->coups++;
		print_stacks(g);
	}
	return (1);
}

int		reverse_rotate_a(t_global *g)
{
	char	*last;
	char	*tmp;
	int		i;

	i = 0;
	if (len(g->a) < 1)
		return (-1);
	last = g->a[i];
	while (i < len(g->a) - 1)
	{
		tmp = g->a[i];
		g->a[i] = g->a[i + 1];
		g->a[i + 1] = tmp;
		i++;
	}
	g->a[len(g->a) - 1] = last;
	g->coups++;
	if (!g->action || ft_strncmp(g->action, "rrr", 4))
	{
		if (!(g->action = ft_strdup("rra")) || !add_lst_to_free(g, g->action))
			ft_exit(g);
		g->coups++;
		print_stacks(g);
	}
	return (1);
}

int		rotate_both(t_global *g)
{
	if (len(g->b) >= 2 && len(g->a) >= 2)
	{
		if (!(g->action = ft_strdup("rr")) || !add_lst_to_free(g, g->action))
			ft_exit(g);
		rotate_b(g);
		rotate_a(g);
		g->coups++;
	}
	else
		return (0);
	print_stacks(g);
	return (1);
}
