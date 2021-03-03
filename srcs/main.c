/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:58:48 by thallard          #+#    #+#             */
/*   Updated: 2021/03/03 16:29:13 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

int		ft_contains_alpha(char *num)
{
	int		i;

	i = -1;
	while (num[++i])
		if (!ft_isdigit(num[i]))
			return (0);
	return (1);
}

int		ft_check_doubles(t_global *g, int argc)
{
	int		i;
	int		j;

	j = 0;
	i = -1;
	while (j++ < argc - 2 && (i = -1) < 0)
		while (g->a[++i])
			if (!ft_strncmp(g->a[i], g->a[j], ft_strlen(g->a[i])))
				return (0);
	return (1);
}

int		ft_init_stack(t_global *g, int argc, char **argv)
{
	int		i;
	int		j;

	j = -1;
	i = 0;
	g->a = malloc(sizeof(char *) * argc);
	while (++i < argc && argv[i])
		if (!ft_contains_alpha(argv[i]))
			return (0);
		g->a[++j] = argv[i];
	g->a[++j] = NULL;
	if (!ft_check_doubles(g, argc))
		return (0);
	return (1);
}


int		main(int argc, char **argv)
{
	t_global	*global;

	global = malloc(sizeof(t_global));
	if (!ft_init_stack(global, argc, argv))
		printf("Error\n");
	print_stack(global);
	return (0);
}