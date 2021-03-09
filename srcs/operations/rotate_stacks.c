/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:17:24 by thallard          #+#    #+#             */
/*   Updated: 2021/03/08 21:32:23 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

// ra : rotate a - décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.

void	rotate_a(t_global *g)
{
	char	*first;
	char	*tmp;
	int		i;

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
	print_stacks(g);
}

void	rotate_b(t_global *g)
{
	char	*first;
	char	*tmp;
	int		i;

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
	print_stacks(g);
}

void	reverse_rotate_b(t_global *g)
{
	char	*last;
	char	*tmp;
	int		i;

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
	print_stacks(g);
}

void	reverse_rotate_a(t_global *g)
{
		char	*last;
	char	*tmp;
	int		i;

	i = 0;
	if (get_tab_length(g->a) >= 2)
	{
		last = g->a[i];
		while (i < get_tab_length(g->a) - 1)
		{
			tmp = g->a[i];
			g->a[i] = g->a[i + 1];
			g->a[i + 1] = tmp;
			i++;
		}
		g->a[get_tab_length(g->a) - 1] = last;
		
		print_stacks(g);
	}
}