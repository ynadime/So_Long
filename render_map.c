/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:04:12 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/13 19:04:14 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_to_window(t_data *data, int x, int y)
{
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img_floor, x
			* data->tile_size, y * data->tile_size);
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img_wall, x
			* data->tile_size, y * data->tile_size);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img_collectible, x
			* data->tile_size, y * data->tile_size);
	else if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img_player, x
			* data->tile_size, y * data->tile_size);
	else if (data->map[y][x] == 'E')
	{
		if (data->total_collectibles == data->crystals_collected)
			mlx_put_image_to_window(data->mlx, data->win, data->img_active_exit,
				x * data->tile_size, y * data->tile_size);
		else
			mlx_put_image_to_window(data->mlx, data->win,
				data->img_inactive_exit, x * data->tile_size, y
				* data->tile_size);
	}
}

void	render_map(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			put_image_to_window(data, x, y);
			x++;
		}
		y++;
	}
}
