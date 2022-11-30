/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:47:21 by caubry            #+#    #+#             */
/*   Updated: 2022/11/30 20:42:21 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_over_under(char *under_over, int y)
{
	int	i;

	i = -1;
	if (y == 0)
		i = 0;
	while (under_over[y + i] && i < 2)
	{
		if (!ft_strchr("12", under_over[y + i]))
			return (false);
		i++;
	}
	return (true);
}

bool	check_side(char *empty, int y)
{
	if (!ft_strchr("12", empty[y - 1]))
		return (false);
	if (!ft_strchr("12", empty[y + 1]))
		return (false);
	return (true);
}

bool	inside_map(char **map, int x, t_map *config)
{
	int	y;

	y = 0;
	while (map[x][y])
	{
		if (map[x][y] == '2')
		{
			if (!check_over_under(map[x - 1], y)
				|| !check_over_under(map[x + 1], y)
				|| !check_side(map[x], y))
				return (false);
		}
		else if (ft_strchr("NSEW", map[x][y]))
		{
			if (config->player == '\0')
				config->player = map[x][y];
			else
				return (false);
		}
		else if (!ft_strchr("01", map[x][y]))
			return (false);
		y++;
	}
	return (true);
}

bool	check_first_last_line(char **map, int x)
{
	int		y;
	bool	close;

	y = 0;
	while (map[x][y])
	{
		if (map[x][y] != '1' && map[x][y] != '2')
			return (false);
		if (x == 0 && map[x][y] == '2')
			close = check_over_under(map[x + 1], y);
		else if (x != 0 && map[x][y] == '2')
			close = check_over_under(map[x - 1], y);
		if (!close)
			return (false);
		y++;
	}
	return (true);
}

bool	map_is_closed(char **map, int height, t_map *config)
{
	int		x;

	x = 0;
	while (map[x])
	{
		if (x == 0 || x == height - 1)
		{
			if (!check_first_last_line(map, x))
				return (false);
		}
		else
			if (!inside_map(map, x, config))
				return (ft_printf("Error\nProbleme de configuration de la map\n"),
					false);
		x++;
	}
	if (config->player == '\0')
		return (false);
	return (true);
}
