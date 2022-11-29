/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:08:29 by caubry            #+#    #+#             */
/*   Updated: 2022/11/29 17:21:50 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	init_color(char *tmp, int *color)
{
	int	i;
	int	j;
	int	rgb;
	int	comma;

	i = 2;
	comma = 0;
	while(tmp[i])
	{
		rgb = 0;
		j = 0;
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
		i += j + 1;
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
	int			*map_color[2] = {map->color_floor, map->color_ceiling};
	int	i;

	i = 0;
	while (ft_strncmp(tmp, color[i], 2))
		i++;
	if (map_color[i][3] != 0)
		return (ft_printf("Error\nProbleme de configuration des couleurs\n"),
			free(tmp), false);
	if (!init_color(tmp, map_color[i]))
		return (ft_printf("Error\nProbleme de configuration des couleurs\n"), false);
	free(tmp);
	return (true);
}

bool	init_textures(char *tmp, int i, t_map *map)
{
	int j;
	int fd;

	j = 2;
	while (tmp[j] && tmp[j] == ' ')
		j++;
	map->texture[i] = ft_strtrim(ft_strdup(tmp + j), "\n");
	fd = open(map->texture[i], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		perror(map->texture[i]);
		free(map->texture[i]);
		return (false);
	}
	close(fd);
	return (true);
}

bool	check_texture(char	*tmp, t_map *map) {
	const char	*dir[4] = {"NO ", "SO ", "WE ", "EA "};
	int i;

	i = 0;
	while (ft_strncmp(tmp, dir[i], 3))
		i++;
	if (map->texture[i])
		return (ft_printf("Error\nProbleme de configuration des textures\n"),
			free(tmp), false);
	if (!init_textures(tmp, i, map))
		return (false);
	free(tmp);
	return (true);
}

int		is_texture_or_color(char *tmp)
{
	const char	*dir[4] = {"NO ", "SO ", "WE ", "EA "};
	const char	*color[2] = {"F ", "C "};
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!ft_strncmp(tmp, dir[i], 3))
			return (free(tmp), 1);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (!ft_strncmp(tmp, color[i], 2))
			return (free(tmp), 2);
		i++;
	}
	ft_printf("Error\nErreur de configuration\n");
	return (free(tmp), 0);
}
