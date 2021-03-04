/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:58:48 by thallard          #+#    #+#             */
/*   Updated: 2021/03/04 15:33:35 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

int		ft_contains_alpha(char *num)
{
	int		i;

	i = -1;
	while (num[++i])
		if (!ft_isdigit(num[i]) && num[i] != '-')
			return (0);
	return (1);
}

int		ft_check_doubles(t_global *g, int argc)
{
	int		i;
	int		j;

	j = -1;
	i = -1;
	while (++j < argc && (i = -1) < 0)
		while (g->a[++i] && g->a[j])
			if (i != j)
			if (!ft_strncmp(g->a[i], g->a[j], 11))
				return (0);
	return (1);
}

int		ft_init_stack(t_global *g, int argc, char **argv)
{
	int		i;
	int		j;

	j = -1;
	i = 0;
	g->a = malloc(sizeof(char *) * argc);
	g->b = malloc(sizeof(char *) * argc);
	g->b[0] = NULL;
	while (++i < argc && argv[i])
	{
		if (!ft_contains_alpha(argv[i]))
			return (0);
		g->a[++j] = ft_itoa(ft_atoi(argv[i]));
	}
	g->a[++j] = NULL;
	if (!ft_check_doubles(g, argc))
		return (0);
	return (1);
}

int		ft_split_stacks(t_global *g)
{
	int		i;

	i = -1;
	while (get_tab_length(g->a) != 0)
	{
		push_b(g);
		// if (get_tab_length(g->a) >= 2 && ft_atoi(g->a[get_tab_length(g->a) - 1]) > ft_atoi(g->a[get_tab_length(g->a) - 2]))
		// 	swap_a(g);
		if (get_tab_length(g->b) >= 2 && ft_atoi(g->b[get_tab_length(g->b) - 1]) < ft_atoi(g->b[get_tab_length(g->b) - 2]))
			swap_b(g);
		
	}
	return (1);
}


int		main(int argc, char **argv)
{
	t_global	*global;

	global = malloc(sizeof(t_global));
	global->coups = 0;
	if (!ft_init_stack(global, argc, argv))
	{
			printf("Error\n");
		exit(0);	
	}
	


	printf("\x1b[2J");
	print_stacks(global);

	// swap_a(global);
	// push_b(global);
	// push_b(global);
	// push_b(global);
	// push_b(global);
	ft_split_stacks(global);
	// push_a(global);
	return (0);
}