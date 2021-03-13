/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 01:51:41 by thallard          #+#    #+#             */
/*   Updated: 2021/03/13 15:44:34 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		ft_contains_alpha(char *num)
{
	int		i;

	i = -1;
	while (num[++i])
		if (!ft_isdigit(num[i]) && num[i] != '-' && num[i] != ' ')
			return (0);
	return (1);
}

int				ft_check_doubles(t_global *g, int argc)
{
	int		i;
	int		j;

	j = -1;
	i = -1 + g->vizualizer;
	while (++j < argc && (i = -1 + g->vizualizer) < 0)
		while (g->a[++i] && g->a[j])
			if (i != j)
				if (!ft_strncmp(g->a[i], g->a[j], 11))
					return (0);
	return (1);
}

int				fill_content_spaces(t_global *g, int line, char *str)
{
	int		i;

	i = -1;
	while (++i <= (int)ft_strlen(str) && str[i])
		if (str[i] != ' ')
		{
			if (!(g->a[++line] = ft_itoa(ft_atoi(&str[i])))
				|| !add_lst_to_free(g, g->a[line]))
				ft_exit(g);
			i += ft_strlen(g->a[line]);
		}
	return (line);
}

int				ft_init_stack(t_global *g, int argc, char **a)
{
	int		i;
	int		j;

	j = -1;
	i = 0 + g->vizualizer;
	if (!(g->b = malloc_lst(sizeof(char *) * count_nb_words(g, a), g))
	|| !(g->a = malloc_lst(sizeof(char *) * count_nb_words(g, a), g)))
		ft_exit(g);
	g->b[0] = NULL;
	while (++i < argc && a[i])
	{
		if (!ft_contains_alpha(a[i]))
			return (0);
		if (ft_strchr(a[i], ' '))
			j = fill_content_spaces(g, j, a[i]);
		else if (!(g->a[++j] = ft_itoa(ft_atoi(a[i])))
				|| !add_lst_to_free(g, g->a[j]))
			ft_exit(g);
	}
	g->a[++j] = NULL;
	if (!ft_check_doubles(g, argc))
		return (0);
	return (1);
}
