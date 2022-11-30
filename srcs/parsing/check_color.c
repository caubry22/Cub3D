/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:24:10 by caubry            #+#    #+#             */
/*   Updated: 2022/11/30 20:35:22 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	valid_color(char *tmp, int *ptr_i, int comma, int *color)
{
	int	i;
	int	j;
	int	rgb;

	i = *ptr_i;
	j = 0;
	rgb = 0;
	while (tmp[i] && tmp[i] == ' ')
		i++;
	while (tmp[i + j] && ft_isdigit(tmp[i + j]))
	{
		rgb = rgb * 10 + tmp[i + j] - '0';
		j++;
	}
	if (rgb > 255 || !j)
		return (false);
	else
		color[comma] = rgb;
	*ptr_i = i + j + 1;
	return (true);
}

bool	init_color(char *tmp, int *color)
{
	int	i;
	int	comma;

	i = 2;
	comma = 0;
	while (tmp[i])
	{
		if (!valid_color(tmp, &i, comma, color))
			return (false);
		comma++;
	}
	if (comma != 3)
		return (false);
	color[comma] = 1;
	return (true);
}

bool	check_colors(char *tmp, t_map *map)
{
	const char	*color[2] = {"F ", "C "};
	int			*map_color[2];
	int			i;

	i = 0;
	map_color[0] = map->color_floor;
	map_color[1] = map->color_ceiling;
	while (ft_strncmp(tmp, color[i], 2))
		i++;
	if (map_color[i][3] != 0)
		return (ft_printf("Error\nProbleme de configuration des couleurs\n"),
			free(tmp), false);
	if (!init_color(tmp, map_color[i]))
		return (ft_printf("Error\nProbleme de configuration des couleurs\n"),
			false);
	free(tmp);
	return (true);
}
