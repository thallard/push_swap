/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparaisons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:33:46 by thallard          #+#    #+#             */
/*   Updated: 2021/03/13 14:25:58 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int			is_max(t_global *g, char **stack, int value)
{
	int		i;

	(void)g;
	i = len(stack);
	while (--i >= 0)
		if (value < ft_atoi(stack[i]))
			return (0);
	return (1);
}

int			find_max(t_global *g, char **stack)
{
	int		i;
	int		save;

	(void)g;
	save = g->min[0];
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

int			find_num_plage(t_global *g, int start, int end)
{
	int		i;
	int		first_find;

	first_find = -36666;
	i = -1;
	while (g->a[++i])
		if (ft_atoi(g->a[i]) >= start && ft_atoi(g->a[i]) <= end)
		{
			first_find = i;
			break ;
		}
	if (first_find == -36666)
		return (-36666);
	i = len(g->a);
	while (--i > 0)
		if (ft_atoi(g->a[i]) >= start && ft_atoi(g->a[i]) <= end)
		{
			if (first_find == 0 && i == len(g->a) - 1)
				return (i);
			else
				return (first_find);
		}
	return (first_find);
}
