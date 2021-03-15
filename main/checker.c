/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:38:22 by thallard          #+#    #+#             */
/*   Updated: 2021/03/15 13:25:58 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_action(char *str)
{
	if (ft_strncmp(str, "sa", 3) && ft_strncmp(str, "sb", 3)
		&& ft_strncmp(str, "pa", 3) && ft_strncmp(str, "pb", 3)
		&& ft_strncmp(str, "ra", 3) && ft_strncmp(str, "rb", 3)
		&& ft_strncmp(str, "rrb", 4) && ft_strncmp(str, "rra", 4)
		&& ft_strncmp(str, "ss", 3))
		return (0);
	return (1);
}

void	filter(t_global *g, char *act)
{
	if (!ft_strncmp(act, "sa", 3))
		swap_a(g);
	if (!ft_strncmp(act, "sb", 3))
		swap_b(g);
	if (!ft_strncmp(act, "ss", 3))
		swap_both(g);
	if (!ft_strncmp(act, "pa", 3))
		push_a(g);
	if (!ft_strncmp(act, "pb", 3))
		push_b(g);
	if (!ft_strncmp(act, "ra", 3))
		rotate_a(g);
	if (!ft_strncmp(act, "rb", 3))
		rotate_b(g);
	if (!ft_strncmp(act, "rra", 4))
		reverse_rotate_a(g);
	if (!ft_strncmp(act, "rrb", 4))
		reverse_rotate_b(g);
	// if (!ft_strncmp(act, "rrr", 3))
	// 	push_b(g);
}

int		main(int argc, char **argv)
{
	t_global	*global;
	char *buf;

	if (!(global = malloc(sizeof(t_global))))
		return (printf("A malloc has failed.\n"));
	init_global_struct(global);
	if (argc <= 1)
		return (0);
	if (!ft_strncmp("-v", argv[1], 3))
		global->vizualizer++;
	if (!ft_init_stack(global, argc, argv))
	{
		printf("Error\n");
		return (0);
	}
	reverse_tab(global);
	create_reference_tab(global);
	// if (is_sorted(global))
	// {
	// 	printf("OK\n");
	// 	return (0);
	// }
	while (	get_next_line(0, &buf))
	{
		// if (is_sorted(global) && len(global->a) >= 2)
		// 	break ;
		filter(global, buf);
	if (!is_action(buf))
	{
		printf("Error\n");
		return (0);
	}
	if (is_sorted(global) && len(global->b) == 0)
		break ;
	if (is_sorted(global) && len(global->b) == 0)
		break ;
	}
	if (is_sorted(global))
		printf("OK\n");
	else
		printf("KO\n");
	free(global);
	return (0);
}