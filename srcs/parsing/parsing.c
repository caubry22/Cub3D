/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:08:11 by caubry            #+#    #+#             */
/*   Updated: 2022/11/29 19:22:00 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_extension(char *map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (map[i])
		i++;
	tmp = map + i - 4;
	if (ft_strcmp(tmp, ".cub"))
		return (false);
	return (true);
}

bool	check_map(char *tmp, t_map *map)
{
	int i;
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

bool	parsing_loop(char *tmp, int *i, t_map *map)
{
	bool	check;

	if (tmp_length(ft_strtrim(tmp, " ")) > 0 || *i > 5)
	{
		if (*i < 6)
		{
			if (is_texture_or_color(ft_strtrim(tmp, " ")) == 1)
				check = check_texture(ft_strtrim(tmp, " "), map);
			else if (is_texture_or_color(ft_strtrim(tmp, " ")) == 2)
				check = check_colors(ft_strtrim(tmp, " "), map);
			else
				return (free(tmp), false);
		}
		else
		{
			if (*i == 6 && tmp_length(ft_strtrim(tmp, " \n"))== 0)
				return (true);
			check = check_map(ft_strtrim(tmp, "\n"), map);
		}
		if (!check)
			return (free(tmp), false);
		(*i)++;
	}
	return (true);
}

void	fill_line(char *real_map, char *tab_map, int width)
{
	int	i;
	int	j;
	int	tab;

	i = 0;
	j = 0;
	while (tab_map[i])
	{
		tab = 0;
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

bool	parsing(int ac, char **av, t_map *map)
{
	int		i;
	int		fd;
	char	*tmp;
	char	*map_in_line;

	i = 0;
	if (ac != 2)
		return (false);
	if (!check_extension(av[1]))
		return (ft_printf("Error\nLe fichier n'est pas au bon format (.cub)\n"),
			false);
	fd = open(av[1], O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		if (!parsing_loop(tmp, &i, map))
			return (false);
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp && i == 6)
			map_in_line = ft_strdup(tmp);
		else if (tmp && i > 6)
			map_in_line = ft_strjoin(map_in_line, tmp);
	}
	create_map(map, i - 6, map_in_line);
	print_map(map);
	return (free(tmp), true);
}

void	print_map(t_map *map)
{
	int i;

	i = 0;
	ft_printf("north texture = %s\n", map->texture[0]);
	ft_printf("south texture = %s\n", map->texture[1]);
	ft_printf("west texture = %s\n", map->texture[2]);
	ft_printf("east texture = %s\n", map->texture[3]);
	ft_printf("color floor = %d,%d,%d\n", map->color_floor[0], map->color_floor[1], map->color_floor[2]);
	ft_printf("color ceiling = %d,%d,%d\n", map->color_ceiling[0], map->color_ceiling[1], map->color_ceiling[2]);
	ft_printf("map width = %d\n", map->size[0]);
	ft_printf("map height = %d\n", map->size[1]);
	while (map->init_map[i])
	{
		ft_printf("%s\n", map->init_map[i]);
		i++;
	}
}
