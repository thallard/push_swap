/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:04:25 by thallard          #+#    #+#             */
/*   Updated: 2021/03/03 17:17:57 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

int		get_tab_length(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		;
	return (i);
}

void	print_stack(t_global *g)
{
	int		i;

	i = -1;
	printf("\n");
	while (g->a[++i])
	{
		printf("%s\n", g->a[i]);
	}
	printf("\n");
}