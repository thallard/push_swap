/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:06:00 by thallard          #+#    #+#             */
/*   Updated: 2021/03/03 17:15:54 by thallard         ###   ########lyon.fr   */
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

}					t_global;

void	print_stack(t_global *g);
int		get_tab_length(char **tab);

int		swap_a(t_global *g);

#endif