/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:03:30 by thallard          #+#    #+#             */
/*   Updated: 2021/03/16 10:26:32 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*malloc_lst(int size, t_global *global)
{
	void		*ptr;

	if (!(ptr = malloc(size)))
		return (NULL);
	if (!(add_lst_to_free(global, ptr)))
		return (NULL);
	return (ptr);
}

void	*add_lst_to_free(t_global *global, void *ptr)
{
	t_malloc	*new;

	if (!(new = ft_lstmalloc_new(ptr)))
	{
		free(ptr);
		return (NULL);
	}
	ft_lstmalloc_add_back(&global->lst_free, new);
	return (ptr);
}

int		ft_exit(t_global *g, int val)
{
	ft_lstmalloc_clear(&g->lst_free, free);
	if (val == 1)
		printf("A malloc has failed.\n");
	if (val == 0)
		printf("Error\n");
	exit(0);
}
