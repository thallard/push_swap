/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:04:25 by thallard          #+#    #+#             */
/*   Updated: 2021/03/13 15:44:34 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			len(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void		init_global_struct(t_global *global)
{
	global->coups = 0;
	global->vizualizer = 0;
	global->action = NULL;
	global->lst_free = NULL;
}

void		create_reference_tab(t_global *g)
{
	int		size;
	int		temp;
	int		i;

	i = 0;
	size = -1;
	g->min = malloc_lst(sizeof(int) * 1000, g);
	while (g->a[++size])
		g->min[size] = ft_atoi(g->a[size]);
	g->size = size;
	while (i < (size - 1))
	{
		if (g->min[i] > g->min[i + 1])
		{
			temp = g->min[i];
			g->min[i] = g->min[i + 1];
			g->min[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int			define_plages(t_global *g)
{
	int		plages;
	int		length;

	plages = 0;
	length = len(g->a);
	if (length <= 10)
		plages = 5;
	if (length >= 10 && length <= 50)
		plages = 10;
	if (length >= 50 && length <= 100)
		plages = 20;
	else if (length <= 50)
		plages = 20;
	else if (length >= 100 && length <= 300)
		plages = 35;
	else if (length >= 300)
		plages = 50;
	return (plages);
}

int			count_nb_words(t_global *g, char **argv)
{
	int			nb;
	int			i;
	int			j;

	(void)g;
	i = 0;
	nb = 2;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] && argv[i][j] != ' ')
				j++;
			nb++;
			while (argv[i][j] && argv[i][j] == ' ')
				j++;
		}
	}
	return (nb + 1);
}
