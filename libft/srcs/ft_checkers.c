/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 08:40:20 by thallard          #+#    #+#             */
/*   Updated: 2020/12/14 13:52:25 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
	|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int		ft_is_digit(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}

int		ft_is_spec(int c)
{
	if (c == '.' || c == '*' || c == '0' || c == '-')
		return (1);
	return (0);
}

int		ft_is_flag(int c)
{
	if ((ft_is_type(c) || ft_is_digit(c) || ft_is_spec(c) || c == '%'))
		return (1);
	return (0);
}
