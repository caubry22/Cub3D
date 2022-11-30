/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:51:29 by caubry            #+#    #+#             */
/*   Updated: 2022/11/30 20:36:45 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	loop_fill_line(int *ptr_i, int *ptr_j, char *real_map, char *tab_map)
{
	int	tab;
	int	i;
	int	j;

	tab = 0;
	i = *ptr_i;
	j = *ptr_j;
	if (tab_map[i] == '	')
	{
		while (tab < 4)
		{
			real_map[i + j + tab] = '2';
			tab++;
		}
		j = j + 3;
	}
	else if (tab_map[i] == ' ')
		real_map[i + j] = '2';
	else
		real_map[i + j] = tab_map[i];
	*ptr_i = i;
	*ptr_j = j;
}

void	fill_line(char *real_map, char *tab_map, int width)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab_map[i])
	{
		loop_fill_line(&i, &j, real_map, tab_map);
		i++;
	}
	while (i + j < width)
	{
		real_map[i + j] = '2';
		i++;
	}
	real_map[i + j] = '\0';
}

void	create_map(t_map *map, int height, char *map_in_line)
{
	char	**tab_map;
	char	**real_map;
	int		i;

	map->size[1] = height;
	i = 0;
	tab_map = ft_split(map_in_line, '\n');
	real_map = malloc(sizeof(char *) * (height + 1));
	if (!real_map)
		return ;
	while (i < height)
	{
		real_map[i] = malloc(sizeof(char) * (map->size[0] + 1));
		if (!real_map[i])
			return ;
		fill_line(real_map[i], tab_map[i], map->size[0]);
		i++;
	}
	tab_map[i] = NULL;
	map->init_map = real_map;
}

bool	check_map(char *tmp, t_map *map)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (tmp[i])
	{
		if (tmp[i] == '	')
			width += 4;
		else
			width++;
		i++;
	}
	if (width > map->size[0])
		map->size[0] = width;
	if (width == 0)
		return (ft_printf("Error\nErreur de configuration de la map"),
			false);
	return (true);
}
