/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:06:00 by thallard          #+#    #+#             */
/*   Updated: 2021/03/12 02:45:19 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
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
	int				push;
	int				start;
	int				end;
	int				increment;
}					t_global;

void		print_stacks(t_global *g);
int			raise_plage(t_global *g);
int			len(char **tab);
int			define_plages(t_global *g);
void		init_global_struct(t_global *g);
void		create_reference_tab(t_global *g);

int			swap_a(t_global *g);
int			swap_b(t_global *g);
int			push_a(t_global *g);
int			push_b(t_global *g);
int			rotate_a(t_global *g);
int			rotate_b(t_global *g);
int			reverse_rotate_b(t_global *g);
int			reverse_rotate_a(t_global *g);

int			is_max(t_global *g, char **stack, int value);
int			find_num(t_global *g, char **stack, int value);
int			find_max(t_global *g, char **stack);
int			find_min(t_global *g, char **stack);
int			find_num_plage(t_global *g, int start, int end);

int			ft_check_doubles(t_global *g, int argc);
int			fill_content_spaces(t_global *g, int line, char *str);
int			ft_init_stack(t_global *g, int argc, char **argv);

void		*add_lst_to_free(t_global *global, void *ptr);
void		*malloc_lst(int size, t_global *global);
int			ft_exit(t_global *g);

t_malloc	*ft_lstmalloc_new(void *content);
t_malloc	*ft_lstmalloc_last(t_malloc *lst);
void		ft_lstmalloc_add_back(t_malloc **alst, t_malloc *new);
void		ft_lstmalloc_clear(t_malloc **lst, void (*del)(void *));
#endif