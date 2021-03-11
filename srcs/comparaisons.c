/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparaisons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:33:46 by thallard          #+#    #+#             */
/*   Updated: 2021/03/11 17:34:58 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

int		is_max(t_global *g, char **stack, int value)
{
	int		i;

	(void)g;
	i = get_tab_length(stack);
	while (--i >= 0)
	{
		if (value < ft_atoi(stack[i]))
			return (0);
	}
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
	i = get_tab_length(g->a);
	while (--i > 0)
	{
	dprintf(1, "valeur oui= %s %d %d\n", g->a[i], i, get_tab_length(g->a) - 1);

		if (ft_atoi(g->a[i]) >= start && ft_atoi(g->a[i]) <= end)
		{
			if (first_find == 0 && i == get_tab_length(g->a) - 1)	
			{
				dprintf(1, "\n\n return ici11111111 \n\n");
					return (i);
			}
			
	// 		if (get_tab_length(g->a) - i < first_find && first_find != 0)
	// 		{
	// dprintf(1, "\n\n return ici111ewqqeweqw11111 \n\n");
	// 	return (i);
	// 		}
			
			else
			{
				dprintf(1, "return icicieiqwieiqwiiqieqwiiqw\n\n");
					return (first_find);
			}
			
		}
		}
	return (first_find);
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