/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:46:41 by thallard          #+#    #+#             */
/*   Updated: 2021/03/16 10:41:23 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list		*new;
	t_list		*list;

	if (!l)
		return (NULL);
	if (!(list = ft_lstnew(f(l->content))))
		return (NULL);
	new = list;
	while (l->next)
	{
		l = l->next;
		if (!(list->next = ft_lstnew(f(l->content))))
		{
			ft_lstclear(&new, d);
			return (NULL);
		}
		list = list->next;
	}
	return (new);
}
