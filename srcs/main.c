/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:58:48 by thallard          #+#    #+#             */
/*   Updated: 2021/03/11 17:29:59 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

int		ft_contains_alpha(char *num)
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
	{
		if (str[i] != ' ')
		{
			dprintf(1, "debug de str = %s\n", &str[i]);
			g->a[++line] = ft_itoa(ft_atoi(&str[i]));
			i += ft_strlen(g->a[line]);
		}
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

int		ft_split_stacks(t_global *g)
{
	int		i;
	int		pos;
	int		start, end;
	int		push;
	int		increment;

	increment = 5;
	push = 5;
	start = g->min[0];
	end = g->min[5];
	pos = 0;
	i = -1;
	while (get_tab_length(g->a) != 0)
	{
		// push_b(g);
		dprintf(1, "debug end et start = %d %d\n\n", start, end);
		pos = find_num_plage(g, start, end);
		if (pos == -36666)
		{
			dprintf(1, "debug end et start dans le if pos = -1   = %d %d\n\n", start, end);
			start = g->min[push];
			push += increment;
			end = g->min[push];
			// end += push;
			// start += push;
			continue ;
		}
		if (pos == get_tab_length(g->a) - 1)
			push_b(g);
		else if (get_tab_length(g->a) / 2 <= pos)
		{
			while (pos-- > 0)
				rotate_a(g);
			push_b(g);
		}
		else if (get_tab_length(g->a) / 2 >= pos)
		{
			if (!pos)
			{
				reverse_rotate_a(g);
				push_b(g);
				continue ;
			}
			while (pos-- >= 0)
				reverse_rotate_a(g);
			push_b(g);
		}
	}
		
	while (get_tab_length(g->b) != 0)
	{
		if (get_tab_length(g->b) / 2 <= find_num(g, g->b, find_max(g, g->b)))
		{
				dprintf(1, "debug de pos ici = %d %d\n", find_num(g, g->b, find_max(g, g->b)), find_max(g, g->b));
			while (!is_max(g, g->b, ft_atoi(g->b[get_tab_length(g->b) - 1])))
				rotate_b(g);
			push_a(g);
		}
		if (get_tab_length(g->b) / 2 > find_num(g, g->b, find_max(g, g->b)))
		{
			dprintf(1, "debug de pos ici = %d %d\n", find_num(g, g->b, find_max(g, g->b)), find_max(g, g->b));
			while (!is_max(g, g->b, ft_atoi(g->b[get_tab_length(g->b) - 1])))
				reverse_rotate_b(g);
			push_a(g);
			dprintf(1, "valeur du min = %d\n", find_min(g, g->b));
		}
	}
	return (1);
}


int		main(int argc, char **argv)
{
	t_global	*global;

	global = malloc(sizeof(t_global));
	global->coups = 0;
	global->vizualizer = 0;
	global->action = NULL;
	if (!ft_strncmp("-v", argv[1], 3))
		global->vizualizer++;
	if (!ft_init_stack(global, argc, argv))
	{
			printf("Error\n");
		exit(0);	
	}
	global->lst_free = NULL;
	global->min = malloc_lst(sizeof(int) * 1000, global);
	int size = -1;
	while (global->a[++size])
	{
		global->min[size] = ft_atoi(global->a[size]);
	}
	global->size = size;
	int		temp;
	int 	i;
	i = 0;
	while (i < (size - 1))
	{
		if (global->min[i] > global->min[i + 1])
		{
			temp = global->min[i];
			global->min[i] = global->min[i + 1];
			global->min[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}

	printf("\x1b[2J");
	print_stacks(global);
	ft_split_stacks(global);
	return (0);
}