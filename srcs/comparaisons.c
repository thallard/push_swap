/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparaisons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:33:46 by thallard          #+#    #+#             */
/*   Updated: 2021/03/05 14:32:57 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

int		is_max(t_global *g, char **stack, int value)
{
	int		i;

	(void)g;
	i = get_tab_length(stack) - 1;
	while (i > 0)
	{
		dprintf(1, "valeur de ismax = %s et %d\n", stack[i], value);
		if (value < ft_atoi(stack[i]))
			return (0);
		i--;
	}
	return (1);
}

// int		get_min(t_global *g, char **stack)
// {
// 	int			loop;
// 	int			i;
	
// 	loop = 1;
// 	while (loop)
// 	{
// 		loop = 1;
// 		i = -1;
	
// 		while (stack[++i])
// 			if (g->min == ft_atoi(stack[i]))
// 				loop = 0;
// 		if (loop)
// 			g->min++;
// 	}
// 	return (g->min);
// }