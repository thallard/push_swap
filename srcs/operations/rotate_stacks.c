/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:17:24 by thallard          #+#    #+#             */
/*   Updated: 2021/03/04 15:32:55 by thallard         ###   ########lyon.fr   */
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