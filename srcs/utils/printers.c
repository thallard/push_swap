/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:51:47 by thallard          #+#    #+#             */
/*   Updated: 2021/03/11 17:34:02 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

void	print_stack_a(t_global *g)
{
	int		i;

	i = -1;
	printf("\n");
	while (g->a[++i])
	{
		printf("\033[0;33m%s\n", g->a[i]);
	}
	printf("\n");
}

void	print_stack_b(t_global *g)
{
	int		i;

	i = -1;
	printf("Pile B :\n");
	while (g->b[++i])
		printf("\033[1;32m%s\n", g->b[i]);
	printf("\n");
}

void	print_stacks(t_global *g)
{
	int		i;

	usleep(200000);
	i = -1;
	printf("\x1b[2J");
    printf("\x1b[H");
    printf("\e[0m|_______________|_______________|\n");
    printf("|\e[92m%-15s\e[0m|\e[93m%15s\e[0m|\n","STACK A", "STACK B");
    printf("|_______________|_______________|\n");
	while (++i < 99999)
	{
		if (i > get_tab_length(g->b) && i > get_tab_length(g->a))
			break ;
		if (i < get_tab_length(g->a))
			printf("|\e[92m%7s        \e[0m", g->a[get_tab_length(g->a) - 1 - i]);
		else
			printf("|\e[92m%7s        \e[0m", "\0");
		if (i < get_tab_length(g->b))
			printf("|\e[93m%7s        \e[0m|\n",   g->b[get_tab_length(g->b) - 1 -i]);
		else
			printf("|\e[93m%7s        \e[0m|\n", "\0");
	}
	printf("|_______________|_______________|\n");
	printf("| Coups = \033[0;32m%-6d\e[0m| Action = \033[0;35m%-5s\e[0m|\n", g->coups, g->action);

}