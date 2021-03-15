/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:38:22 by thallard          #+#    #+#             */
/*   Updated: 2021/03/15 14:57:51 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_action(char *str)
{
	if (ft_strncmp(str, "sa", 3) && ft_strncmp(str, "sb", 3)
		&& ft_strncmp(str, "pa", 3) && ft_strncmp(str, "pb", 3)
		&& ft_strncmp(str, "ra", 3) && ft_strncmp(str, "rb", 3)
		&& ft_strncmp(str, "rrb", 4) && ft_strncmp(str, "rra", 4)
		&& ft_strncmp(str, "ss", 3) && ft_strncmp(str, "rr", 3)
		&& ft_strncmp(str, "rrr", 4))
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
	if (!ft_strncmp(act, "rr", 3))
		rotate_both(g);
	if (!ft_strncmp(act, "rb", 3))
		rotate_b(g);
	if (!ft_strncmp(act, "rra", 4))
		reverse_rotate_a(g);
	if (!ft_strncmp(act, "rrb", 4))
		reverse_rotate_b(g);
	if (!ft_strncmp(act, "rrr", 4))
		reverse_rotate_both(g);
}

int		check_and_sort(t_global *g)
{
	char		*buf;

	reverse_tab(g);
	create_reference_tab(g);
	while (get_next_line(0, &buf))
	{
		filter(g, buf);
		if (!is_action(buf))
		{
			printf("Error\n");
			return (0);
		}
		if (is_sorted(g) && len(g->b) == 0)
			break ;
		free(buf);
	}
	free(buf);
	return (1);
}

int		main(int argc, char **argv)
{
	t_global	*global;

	if (argc <= 1 || !(global = malloc(sizeof(t_global))))
		return (0);
	init_global_struct(global);
	if (!ft_strncmp("-v", argv[1], 3))
		global->vizualizer++;
	if (!ft_init_stack(global, argc, argv))
	{
		printf("Error\n");
		return (0);
	}
	if (!(check_and_sort(global)))
		return (0);
	if (is_sorted(global))
		printf("OK\n");
	else
		printf("KO\n");
	free(global);
	return (0);
}
