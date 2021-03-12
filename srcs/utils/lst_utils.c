/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:15:25 by thallard          #+#    #+#             */
/*   Updated: 2021/03/12 02:32:55 by thallard         ###   ########lyon.fr   */
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

void	ft_lstmalloc_clear(t_malloc **lst, void (*del)(void *))
{
	t_malloc	*elem;
	t_malloc	*next;

	elem = *lst;
	while (elem)
	{
		next = elem->next;
		if (elem->content)
			del(elem->content);
		free(elem);
		elem = next;
	}
	*lst = NULL;
}