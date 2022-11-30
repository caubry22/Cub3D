/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:09:33 by caubry            #+#    #+#             */
/*   Updated: 2022/11/30 16:27:54 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	int i;

	i = 0;
	while (i < 2)
	{
		map->size[i] = 0;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		map->texture[i] = NULL;
		i++;
	}
	map->color_floor[3] = 0;
	map->color_ceiling[3] = 0;
	map->player = '\0';
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (ft_printf("Error\nIl faut mettre en argument le fichier de description de scene\n"), 1);
	init_map(&map);
	if (!parsing(ac, av, &map))
		return (1);
	return (1);
}
