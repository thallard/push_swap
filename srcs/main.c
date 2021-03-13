/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:58:48 by thallard          #+#    #+#             */
/*   Updated: 2021/03/12 17:17:35 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

int		fill_sort_stack_b(t_global *g)
{
	while (len(g->b) != 0)
	{
		if (len(g->b) / 2 <= find_num(g, g->b, find_max(g, g->b)))
		{
			while (!is_max(g, g->b, ft_atoi(g->b[len(g->b) - 1])))
				if (!rotate_b(g))
					return (0);
			if (!push_a(g))
				return (0);
		}
		if (len(g->b) / 2 > find_num(g, g->b, find_max(g, g->b)))
		{
			while (!is_max(g, g->b, ft_atoi(g->b[len(g->b) - 1])))
				if (!(reverse_rotate_b(g)))
					return (0);
			if (!push_a(g))
				return (0);
		}
	}
	return (1);
}

int		empty_stack_a(t_global *g, int pos)
{
	while (len(g->a) != 0)
	{
		pos = find_num_plage(g, g->start, g->end);
		if (pos == -36666 && raise_plage(g))
			continue ;
		if (pos == len(g->a) - 1)
			push_b(g);
		else if (len(g->a) / 2 <= pos)
		{
			while (pos-- >= 0)
				rotate_a(g);
			push_b(g);
		}
		else if (len(g->a) / 2 > pos)
		{
			if (!pos)
			{
				reverse_rotate_a(g);
				push_b(g);
				continue ;
			}
			while (pos-- >= 0)
				reverse_rotate_a(g);
			push_b(g);
		}
	}
	return (1);
}

int		ft_split_stacks(t_global *g)
{
	g->push = g->increment;
	g->end = g->min[g->increment];
	g->start = g->min[0];
	empty_stack_a(g, 0);
	if (!(fill_sort_stack_b(g)))
		ft_exit(g);
	return (1);
}


int		main(int argc, char **argv)
{
	t_global	*global;

	global = malloc(sizeof(t_global));
	init_global_struct(global);
	if (!ft_strncmp("-v", argv[1], 3))
		global->vizualizer++;
	if (!ft_init_stack(global, argc, argv))
	{
		printf("Error\n");
		return (0);
	}
	create_reference_tab(global);
	global->increment = define_plages(global);
	if (len(global->a) > 6)
		ft_split_stacks(global);
	else
	{
		printf("beosin de creer une nouvelle fonction\n");
		mini_algo(global);
	}
	return (0);
}