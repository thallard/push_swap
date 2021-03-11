/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:06:00 by thallard          #+#    #+#             */
/*   Updated: 2021/03/11 17:31:55 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# include "libft.h"

typedef struct		s_malloc
{
	void			*content;
	struct s_malloc	*next;
}					t_malloc;


typedef struct		s_global
{
	t_malloc		*lst_free;
	char			**a;
	char			**b;
	int				coups;
	int				*min;
	int				size;
	int				vizualizer;
	char			*action;
}					t_global;

void	print_stack_b(t_global *g);
void	print_stacks(t_global *g);
void	print_stack_a(t_global *g);
int		get_tab_length(char **tab);

int		swap_a(t_global *g);
int		swap_b(t_global *g);
int		push_a(t_global *g);
int		push_b(t_global *g);
int		rotate_a(t_global *g);
int		rotate_b(t_global *g);
int		reverse_rotate_b(t_global *g);
int		reverse_rotate_a(t_global *g);

int		is_max(t_global *g, char **stack, int value);
int		get_min(t_global *g, char **stack);
int			find_num(t_global *g, char **stack, int value);
int			find_max(t_global *g, char **stack);
int			find_min(t_global *g, char **stack);
int			find_num_plage(t_global *g, int start, int end);


void	*add_lst_to_free(t_global *global, void *ptr);
void	*malloc_lst(int size, t_global *global);

t_malloc	*ft_lstmalloc_new(void *content);
t_malloc	*ft_lstmalloc_last(t_malloc *lst);
void	ft_lstmalloc_add_back(t_malloc **alst, t_malloc *new);
#endif