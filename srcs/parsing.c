/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 01:51:41 by thallard          #+#    #+#             */
/*   Updated: 2021/03/12 02:46:27 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

static int		ft_contains_alpha(char *num)
{
	int		i;

	i = -1;
	while (num[++i])
		if (!ft_isdigit(num[i]) && num[i] != '-' && num[i] != ' ')
			return (0);
	return (1);
}

int		ft_check_doubles(t_global *g, int argc)
{
	int		i;
	int		j;

	j = -1;
	i = -1 + g->vizualizer;
	while (++j < argc && (i = -1  + g->vizualizer) < 0)
		while (g->a[++i] && g->a[j])
			if (i != j)
				if (!ft_strncmp(g->a[i], g->a[j], 11))
					return (0);
	return (1);
}

int		fill_content_spaces(t_global *g, int line, char *str)
{
	int		i;

	i = -1;
	while (++i <= (int)ft_strlen(str) && str[i])
		if (str[i] != ' ')
		{
			g->a[++line] = ft_itoa(ft_atoi(&str[i]));
			i += ft_strlen(g->a[line]);
		}
	return (line);
}

int		ft_init_stack(t_global *g, int argc, char **argv)
{
	int		i;
	int		j;

	j = -1;
	i = 0 + g->vizualizer;
	g->a = malloc(sizeof(char *) * (argc + 1000));
	g->b = malloc(sizeof(char *) * (argc + 1000));
	g->b[0] = NULL;
	while (++i < argc && argv[i])
	{
		if (!ft_contains_alpha(argv[i]))
			return (0);
		if (ft_strchr(argv[i], ' '))
			j = fill_content_spaces(g, j, argv[i]);
		else
			g->a[++j] = ft_itoa(ft_atoi(argv[i]));
	}
	g->a[++j] = NULL;
	if (!ft_check_doubles(g, argc))
		return (0);
	return (1);
}
