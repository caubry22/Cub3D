/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:08:11 by caubry            #+#    #+#             */
/*   Updated: 2022/11/29 17:24:21 by caubry           ###   ########.fr       */
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

bool	check_map(char *tmp)
{
	(void)*tmp;
	return (true);
}

bool	parsing_loop(char *tmp, int *i, t_map *map)
{
	bool	check;

	if (tmp_length(ft_strtrim(tmp, " ")) > 0 || *i > 5)
	{
		if (*i < 6)
		{
			ft_printf("i = %d && tmp = %s\n", *i, tmp);
			if (is_texture_or_color(ft_strtrim(tmp, " ")) == 1)
				check = check_texture(ft_strtrim(tmp, " "), map);
			else if (is_texture_or_color(ft_strtrim(tmp, " ")) == 2)
				check = check_colors(ft_strtrim(tmp, " "), map);
			else
				return (free(tmp), false);
		}
		else
			check = check_map(tmp);
		if (!check)
			return (free(tmp), false);
		(*i)++;
	}
	return (true);
}

bool	parsing(int ac, char **av, t_map *map)
{
	int		i;
	int		fd;
	char	*tmp;

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
	}
	print_map(map);
	free(tmp);
	return (true);
}

void	print_map(t_map *map)
{
	ft_printf("north texture = %s\n", map->texture[0]);
	ft_printf("south texture = %s\n", map->texture[1]);
	ft_printf("west texture = %s\n", map->texture[2]);
	ft_printf("east texture = %s\n", map->texture[3]);
	ft_printf("color floor = %d,%d,%d\n", map->color_floor[0], map->color_floor[1], map->color_floor[2]);
	ft_printf("color ceiling = %d,%d,%d\n", map->color_ceiling[0], map->color_ceiling[1], map->color_ceiling[2]);
}
