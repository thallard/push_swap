/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:17:24 by thallard          #+#    #+#             */
/*   Updated: 2021/03/11 17:32:53 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	rotate_a(t_global *g)
{
	char	*first;
	char	*tmp;
	int		i;

	if (get_tab_length(g->a) < 1)
		return (0);
	i = get_tab_length(g->a) - 1;
	first = g->a[i];
	while (i > 0)
	{
		tmp = g->a[i];
		g->a[i] = g->a[i - 1];
		g->a[i - 1] = tmp;
		i--;
	}
	g->a[0] = first;
	g->coups++;
	if (!(g->action = ft_strdup("ra")) || !add_lst_to_free(g, g->action))
		return (0);
	if (g->vizualizer)
		print_stacks(g);
		return (1);

}

int	rotate_b(t_global *g)
{
	char	*first;
	char	*tmp;
	int		i;

	if (get_tab_length(g->b) < 1)
		return (0);
	i = get_tab_length(g->b) - 1;
	first = g->b[i];
	while (i > 0)
	{
		tmp = g->b[i];
		g->b[i] = g->b[i - 1];
		g->b[i - 1] = tmp;
		i--;
	}
	g->b[0] = first;
	g->coups++;
	if (!(g->action = ft_strdup("rb")) || !add_lst_to_free(g, g->action))
		return (0);
	if (g->vizualizer)
		print_stacks(g);
	return (1);
}

int	reverse_rotate_b(t_global *g)
{
	char	*last;
	char	*tmp;
	int		i;

	if (get_tab_length(g->b) < 1)
		return (0);
	i = 0;
	last = g->b[i];
	while (i < get_tab_length(g->b) - 1)
	{
		tmp = g->b[i];
		g->b[i] = g->b[i + 1];
		g->b[i + 1] = tmp;
		i++;
	}
	g->b[get_tab_length(g->b) - 1] = last;
	g->coups++;
		if (!(g->action = ft_strdup("rrb")) || !add_lst_to_free(g, g->action))
		return (0);
	if (g->vizualizer)
		print_stacks(g);
	return (1);

}

int	reverse_rotate_a(t_global *g)
{
		char	*last;
	char	*tmp;
	int		i;

	i = 0;
	if (get_tab_length(g->a) < 1)
		return (0);
	last = g->a[i];
	while (i < get_tab_length(g->a) - 1)
	{
		tmp = g->a[i];
		g->a[i] = g->a[i + 1];
		g->a[i + 1] = tmp;
		i++;
	}
	g->a[get_tab_length(g->a) - 1] = last;
	g->coups++;
		if (!(g->action = ft_strdup("rra")) || !add_lst_to_free(g, g->action))
		return (0);
	if (g->vizualizer)
		print_stacks(g);
	return (1);

}