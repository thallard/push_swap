/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:15:25 by thallard          #+#    #+#             */
/*   Updated: 2021/03/10 15:41:55 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

t_malloc	*ft_lstmalloc_new(void *content)
{
	t_malloc	*elem;

	if (!(elem = malloc(sizeof(t_malloc))))
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

t_malloc	*ft_lstmalloc_last(t_malloc *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstmalloc_add_back(t_malloc **alst, t_malloc *new)
{
	t_malloc	*elem;

	if (!(*alst))
		*alst = new;
	else
	{
		elem = ft_lstmalloc_last(*alst);
		elem->next = new;
	}
}