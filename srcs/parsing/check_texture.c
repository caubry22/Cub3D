/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:08:29 by caubry            #+#    #+#             */
/*   Updated: 2022/11/30 20:24:06 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	init_textures(char *tmp, int i, t_map *map)
{
	int	j;
	int	fd;

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

bool	check_texture(char	*tmp, t_map *map)
{
	const char	*dir[4] = {"NO ", "SO ", "WE ", "EA "};
	int			i;

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

int	is_texture_or_color(char *tmp)
{
	const char	*dir[4] = {"NO ", "SO ", "WE ", "EA "};
	const char	*color[2] = {"F ", "C "};
	int			i;

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
