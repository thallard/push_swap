/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparaisons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:33:46 by thallard          #+#    #+#             */
/*   Updated: 2021/03/06 00:39:57 by thallard         ###   ########lyon.fr   */
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
		if (value < ft_atoi(stack[i]))
			return (0);
		i--;
	}
	return (1);
}

int			find_max(t_global *g, char **stack)
{
	int		i;
	int		save;

	(void)g;
	save = 0;
	i = -1;
	while (stack[++i])
		if (save < ft_atoi(stack[i]))
			save = ft_atoi(stack[i]);
	return (save);
}

int			find_min(t_global *g, char **stack)
{
	int		i;
	int		save;

	(void)g;
	save = 2147483647;
	i = -1;
	while (stack[++i])
		if (save > ft_atoi(stack[i]))
			save = ft_atoi(stack[i]);
	return (save);
}

int			find_num(t_global *g, char **stack, int value)
{
	int		i;
	(void)g;
	i = -1;
	while (stack[++i])
		if (value == ft_atoi(stack[i]))
			return (i);
	return (0);
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