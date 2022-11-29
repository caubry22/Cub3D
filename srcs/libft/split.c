/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:19:18 by caubry            #+#    #+#             */
/*   Updated: 2022/11/29 18:37:33 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*__free_tab(char **tab, int *index)
{
	while (*index >= 0)
	{
		free(tab[*index]);
		(*index)--;
	}
	free(tab);
	return (NULL);
}

static int	ft_is_charset(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	__compute_tab_size(char *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (!ft_is_charset(s[i], c))
		{
			while (!ft_is_charset(s[i], c) && s[i])
				i++;
			size++;
		}
		while (ft_is_charset(s[i], c) && s[i])
			i++;
	}
	return (size);
}

static char	*__strdup_spe(char *s, char c, char **tab, int *index)
{
	int		i;
	char	*final_str;

	i = 0;
	while (!ft_is_charset(s[i], c) && s[i])
		i++;
	final_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!(final_str))
		return (__free_tab(tab, index));
	i = 0;
	while (!ft_is_charset(s[i], c) && s[i])
	{
		final_str[i] = s[i];
		i++;
	}
	final_str[i] = '\0';
	return (final_str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		size;
	char	**final_tab;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	size = __compute_tab_size((char *)s, c);
	final_tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (!(final_tab))
		return (0);
	final_tab[0] = 0;
	while (j < size)
	{
		while (s[i] && ft_is_charset(s[i], c))
			i++;
		final_tab[j++] = __strdup_spe((char *)s + i, c, final_tab, &j);
		while (s[i] && !ft_is_charset(s[i], c))
			i++;
	}
	final_tab[j] = 0;
	return (final_tab);
}
