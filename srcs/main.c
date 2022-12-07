/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:09:33 by caubry            #+#    #+#             */
/*   Updated: 2022/12/07 13:03:45 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	int	i;

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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	test_mlx(t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;
	int		i;
	int		j;
	
	mlx = mlx_init();
	x = 0;
	mlx_win = mlx_new_window(mlx, map->size[0] * 32, map->size[1] * 32, "Cub3D");
	img.img = mlx_new_image(mlx, map->size[0] * 32, map->size[1] * 32);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	while (x < map->size[1])
	{
		y = 0;
		while (y < map->size[0])
		{
			if (map->init_map[x][y] == '1')
			{
				i = 0;
				while (i < 32)
				{
					j = 0;
					while (j < 32)
					{
						my_mlx_pixel_put(&img, y * 32 + i, x * 32 + j, 0x00ABCDEF);
						j++;
					}
					i++;
				}
			}
			if (map->init_map[x][y] == 'N')
			{
				my_mlx_pixel_put(&img, y * 32 + 16, x * 32 + 16, 0x00CBFFDB);
				my_mlx_pixel_put(&img, y * 32 + 17, x * 32 + 17, 0x00CBFFDB);
				my_mlx_pixel_put(&img, y * 32 + 15, x * 32 + 15, 0x00CBFFDB);
				my_mlx_pixel_put(&img, y * 32 + 18, x * 32 + 18, 0x00CBFFDB);
				my_mlx_pixel_put(&img, y * 32 + 16, x * 32 + 17, 0x00CBFFDB);
				my_mlx_pixel_put(&img, y * 32 + 17, x * 32 + 16, 0x00CBFFDB);
				my_mlx_pixel_put(&img, y * 32 + 15, x * 32 + 18, 0x00CBFFDB);
				my_mlx_pixel_put(&img, y * 32 + 18, x * 32 + 15, 0x00CBFFDB);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (ft_printf("Error\nIl faut mettre en argument le fichier de description de scene\n"), 1);
	init_map(&map);
	if (!parsing(ac, av, &map))
		return (1);
	test_mlx(&map);
	return (1);
}
