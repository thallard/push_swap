/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <thallard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:41:33 by thallard          #+#    #+#             */
/*   Updated: 2020/11/25 01:16:56 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free_all(char **res, int j)
{
	int		i;

	i = -1;
	while (++i <= j)
		free(res[j]);
	free(res);
}

static int		ft_get_words(char *str, char c)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			nb++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (nb);
}

static char		*ft_create_word(char *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(word = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_split(char *str, char c)
{
	int		i;
	char	**res;
	int		j;

	if (!str || !(res = malloc(sizeof(char *) * (ft_get_words(str, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			if ((res[j++] = ft_create_word(&str[i], c)) == NULL)
			{
				ft_free_all(res, j - 1);
				return (NULL);
			}
			while (str[i] && str[i] != c)
				i++;
		}
	}
	res[j] = 0;
	return (res);
}
