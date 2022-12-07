/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeston <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:18:47 by cmeston           #+#    #+#             */
/*   Updated: 2022/12/07 13:22:54 by cmeston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_player(t_player *data, t_map *map)
{
	data->mlx_id = NULL;
	data->win = NULL;
	data->img = NULL;
	data->img_addr = NULL;
	data->px = map->player_pos[1] * 32 + (32/2);
	data->py = map->player_pos[0] * 32 + (32/2);
	data->delx = cos(data->angle)*5;
	data->dely = sin(data->angle)*5;

	return (0);
}

void	ft_pixel_put(t_player *player, int x, int y, int color)
{
	player->img_addr[y * player->line_length / 4 + x] = color;
}

int	draw_player(t_player *player, int width, int color)
{
	int	i;
	int	j;

	printf("px = %f\n", player->px);
	printf("py = %f\n", player->py);
	player->px -= width / 2;
	player->py -= width / 2;
	if (player->win == NULL)
		return (1);
	i = player->py;
	while (i < player->py + width)
	{
		j = player->px;
		while (j < player->px + width)
			ft_pixel_put(player, j++, i, color);
		++i;
	}
	return (0);
}

// int	ft_kinput(int keysym, t_player *data)
// {
// 	if (keysym == XK_Escape)
// 		ft_closewin(data);
// 	render_rect(data, 10, 10, 0);
// 	draw_line(data->px, data->py, (data->px + data->delx *5), (data->py + data->dely * 5), data, 0);
// 	if (keysym == XK_d || keysym == XK_a || keysym == XK_w || keysym == XK_s)
// 	{
// 		if(keysym == XK_a)
// 		{
// 			data->angle -= 0.1;
// 			if (data->angle < 0)
// 				data->angle += 2 * PI;
// 			data->delx = cos(data->angle)*5;
// 			data->dely = sin(data->angle)*5;
// 		}
// 		else if(keysym == XK_d)
// 		{
// 			data->angle += 0.1;
// 			if (data->angle > 2*PI)
// 				data->angle -= 2 * PI;
// 			data->delx = cos(data->angle)*5;
// 			data->dely = sin(data->angle)*5;
// 		}
// 		else if(keysym == XK_w)
// 		{
// 			data->px += data->delx;
// 			data->py += data->dely;
// 		}
// 		else if(keysym == XK_s)
// 		{
// 			data->px -= data->delx;
// 			data->py -= data->dely;
// 		}
// 	}
// 	else
// 		printf("key = %d", keysym);
// 	render_rect(data, 10, 10, 2552550);
// 	draw_line(data->px, data->py, (data->px + data->delx *5), (data->py + data->dely * 5), data, 2552550);
// 	// mlx_clear_window(data->mlx_id, data->win);
// 	mlx_put_image_to_window(data->mlx_id, data->win, data->img, 0, 0);
// 	return (0);
// }