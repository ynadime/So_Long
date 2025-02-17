/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_frames_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:14:20 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/17 14:56:57 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_player_frames1(t_data *data)
{
	data->img_up[0] = mlx_xpm_file_to_image(data->mlx, "bonus/assets/u1.xpm",
			&data->tile_size, &data->tile_size);
	data->img_up[1] = mlx_xpm_file_to_image(data->mlx, "bonus/assets/u2.xpm",
			&data->tile_size, &data->tile_size);
	data->img_up[2] = mlx_xpm_file_to_image(data->mlx, "bonus/assets/u3.xpm",
			&data->tile_size, &data->tile_size);
	data->img_up[3] = mlx_xpm_file_to_image(data->mlx, "bonus/assets/u4.xpm",
			&data->tile_size, &data->tile_size);
	data->img_down[0] = mlx_xpm_file_to_image(data->mlx, "bonus/assets/d1.xpm",
			&data->tile_size, &data->tile_size);
	data->img_down[1] = mlx_xpm_file_to_image(data->mlx, "bonus/assets/d2.xpm",
			&data->tile_size, &data->tile_size);
	data->img_down[2] = mlx_xpm_file_to_image(data->mlx, "bonus/assets/d3.xpm",
			&data->tile_size, &data->tile_size);
	data->img_down[3] = mlx_xpm_file_to_image(data->mlx, "bonus/assets/d4.xpm",
			&data->tile_size, &data->tile_size);
	data->img_player = data->img_down;
}

void	load_player_frames2(t_data *data)
{
	data->img_left[0] = mlx_xpm_file_to_image(data->mlx, "bonus/assets/l1.xpm",
			&data->tile_size, &data->tile_size);
	data->img_left[1] = mlx_xpm_file_to_image(data->mlx, "bonus/assets/l2.xpm",
			&data->tile_size, &data->tile_size);
	data->img_left[2] = mlx_xpm_file_to_image(data->mlx, "bonus/assets/l3.xpm",
			&data->tile_size, &data->tile_size);
	data->img_left[3] = mlx_xpm_file_to_image(data->mlx, "bonus/assets/l4.xpm",
			&data->tile_size, &data->tile_size);
	data->img_right[0] = mlx_xpm_file_to_image(data->mlx, "bonus/assets/r1.xpm",
			&data->tile_size, &data->tile_size);
	data->img_right[1] = mlx_xpm_file_to_image(data->mlx, "bonus/assets/r2.xpm",
			&data->tile_size, &data->tile_size);
	data->img_right[2] = mlx_xpm_file_to_image(data->mlx, "bonus/assets/r3.xpm",
			&data->tile_size, &data->tile_size);
	data->img_right[3] = mlx_xpm_file_to_image(data->mlx, "bonus/assets/r4.xpm",
			&data->tile_size, &data->tile_size);
}

void	load_enemy_frames1(t_data *data)
{
	data->img_enemy_up[0] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/eu1.xpm", &data->tile_size, &data->tile_size);
	data->img_enemy_up[1] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/eu2.xpm", &data->tile_size, &data->tile_size);
	data->img_enemy_up[2] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/eu3.xpm", &data->tile_size, &data->tile_size);
	data->img_enemy_up[3] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/eu4.xpm", &data->tile_size, &data->tile_size);
	data->img_enemy_down[0] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/ed1.xpm", &data->tile_size, &data->tile_size);
	data->img_enemy_down[1] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/ed2.xpm", &data->tile_size, &data->tile_size);
	data->img_enemy_down[2] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/ed3.xpm", &data->tile_size, &data->tile_size);
	data->img_enemy_down[3] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/ed4.xpm", &data->tile_size, &data->tile_size);
}

void	load_enemy_frames2(t_data *data)
{
	data->img_enemy_left[0] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/el1.xpm", &data->tile_size, &data->tile_size);
	data->img_enemy_left[1] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/el2.xpm", &data->tile_size, &data->tile_size);
	data->img_enemy_left[2] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/el3.xpm", &data->tile_size, &data->tile_size);
	data->img_enemy_left[3] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/el4.xpm", &data->tile_size, &data->tile_size);
	data->img_enemy_right[0] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/er1.xpm", &data->tile_size, &data->tile_size);
	data->img_enemy_right[1] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/er2.xpm", &data->tile_size, &data->tile_size);
	data->img_enemy_right[2] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/er3.xpm", &data->tile_size, &data->tile_size);
	data->img_enemy_right[3] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/er4.xpm", &data->tile_size, &data->tile_size);
}

void	load_crystal_frames(t_data *data)
{
	data->img_collectible[0] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/c1.xpm", &data->tile_size, &data->tile_size);
	data->img_collectible[1] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/c2.xpm", &data->tile_size, &data->tile_size);
	data->img_collectible[2] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/c3.xpm", &data->tile_size, &data->tile_size);
	data->img_collectible[3] = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/c4.xpm", &data->tile_size, &data->tile_size);
}
