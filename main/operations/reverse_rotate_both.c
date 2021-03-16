/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_both.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:21:52 by thallard          #+#    #+#             */
/*   Updated: 2021/03/16 10:16:16 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		reverse_rotate_both(t_global *g)
{
	if (len(g->b) >= 2 && len(g->a) >= 2)
	{
		if (!(g->action = ft_strdup("rrr")) || !add_lst_to_free(g, g->action))
			ft_exit(g, 1);
		reverse_rotate_b(g);
		reverse_rotate_a(g);
		g->coups++;
	}
	else
		return (0);
	print_stacks(g);
	return (1);
}
