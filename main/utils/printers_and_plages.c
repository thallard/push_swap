/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers_and_plages.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:51:47 by thallard          #+#    #+#             */
/*   Updated: 2021/03/15 14:48:08 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		raise_plage(t_global *g)
{
	g->start = g->min[g->push];
	if (g->push + g->increment > g->size)
		g->push = g->size - 1;
	else
		g->push += g->increment;
	g->end = g->min[g->push];
	return (1);
}

int		is_sorted(t_global *g)
{
	int		i;
	int		j;

	j = len(g->a);
	i = -1;
	while (--j > 0 && ++i < g->size - 1)
		if (ft_atoi(g->a[j]) != g->min[i])
			return (0);
	return (1);
}

int		start_prepare_stacks(t_global *g)
{
	int		i;

	i = -1;
	if (!g->vizualizer)
	{
		if (g->action)
			printf("%s\n", g->action);
		return (-1);
	}
	while (++i < 399999999)
		;
	printf("\x1b[2J");
	printf("\x1b[H");
	printf("\e[0m|_______________|_______________|\n");
	printf("|\e[92m%-15s\e[0m|\e[93m%15s\e[0m|\n", "STACK A", "STACK B");
	printf("|_______________|_______________|\n");
	return (0);
}

void	print_stacks(t_global *g)
{
	int		i;

	i = -1;
	if (start_prepare_stacks(g) == -1)
		return ;
	while (++i < 9999999)
	{
		if (i > len(g->b) && i > len(g->a))
			break ;
		if (i < len(g->a))
			printf("|\e[92m%7s        \e[0m", g->a[len(g->a) - 1 - i]);
		else
			printf("|\e[92m%7s        \e[0m", "\0");
		if (i < len(g->b))
			printf("|\e[93m%7s        \e[0m|\n", g->b[len(g->b) - 1 - i]);
		else
			printf("|\e[93m%7s        \e[0m|\n", "\0");
	}
	printf("|_______________|_______________|\n");
	printf("| Coups = \033[0;32m%-6d\e[0m| Action = \033[0;35m%-5s\e[0m|\n",
		g->coups, g->action);
}
