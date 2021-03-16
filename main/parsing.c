/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 01:51:41 by thallard          #+#    #+#             */
/*   Updated: 2021/03/16 10:31:35 by thallard         ###   ########lyon.fr   */
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
		while (g->a_temp[++i] && g->a_temp[j])
			if (i != j)
				if (!ft_strncmp(g->a_temp[i], g->a_temp[j], 11))
					return (0);
	return (1);
}

int				fill_content_spaces(t_global *g, int line, char *str)
{
	int		i;
	long	value;

	i = -1;
	while (++i <= (int)ft_strlen(str) && str[i])
		if (str[i] != ' ')
		{
			value = ft_atoi(&str[i]);
			if (value >= 2147483648)
				ft_exit(g, 0);
			if (!(g->a_temp[++line] = ft_itoa(value))
				|| !add_lst_to_free(g, g->a_temp[line]))
				ft_exit(g, 1);
			i += ft_strlen(g->a_temp[line]);
		}
	return (line);
}

int				ft_init_stack(t_global *g, int argc, char **a)
{
	int		i;
	int		j;

	j = -1;
	i = 0 + g->vizualizer;
	while (++i < argc && a[i])
	{
		if (!ft_contains_alpha(a[i]))
			return (0);
		if (ft_strchr(a[i], ' '))
			j = fill_content_spaces(g, j, a[i]);
		else
		{
			if (ft_atoi(a[i]) >= 2147483648)
				ft_exit(g, 0);
			if (!(g->a_temp[++j] = ft_itoa(ft_atoi(a[i])))
				|| !add_lst_to_free(g, g->a_temp[j]))
				ft_exit(g, 1);
		}
	}
	g->a_temp[++j] = NULL;
	if (!ft_check_doubles(g, argc))
		return (0);
	return (1);
}
