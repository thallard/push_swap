/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:06:00 by thallard          #+#    #+#             */
/*   Updated: 2021/03/04 15:32:26 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# include "libft.h"

typedef struct		s_global
{
	char	**a;
	char	**b;
	int		coups;

}					t_global;

void	print_stack_b(t_global *g);
void	print_stacks(t_global *g);
void	print_stack_a(t_global *g);
int		get_tab_length(char **tab);

int		swap_a(t_global *g);
int		swap_b(t_global *g);
int		push_a(t_global *g);
int		push_b(t_global *g);
void	rotate_a(t_global *g);

#endif