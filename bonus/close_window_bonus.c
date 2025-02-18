/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:14:12 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/18 12:20:03 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_frames(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->img_up[i])
			mlx_destroy_image(data->mlx, data->img_up[i]);
		if (data->img_down[i])
			mlx_destroy_image(data->mlx, data->img_down[i]);
		if (data->img_left[i])
			mlx_destroy_image(data->mlx, data->img_left[i]);
		if (data->img_right[i])
			mlx_destroy_image(data->mlx, data->img_right[i]);
		if (data->img_enemy_up[i])
			mlx_destroy_image(data->mlx, data->img_enemy_up[i]);
		if (data->img_enemy_down[i])
			mlx_destroy_image(data->mlx, data->img_enemy_down[i]);
		if (data->img_enemy_left[i])
			mlx_destroy_image(data->mlx, data->img_enemy_left[i]);
		if (data->img_enemy_right[i])
			mlx_destroy_image(data->mlx, data->img_enemy_right[i]);
		if (data->img_collectible[i])
			mlx_destroy_image(data->mlx, data->img_collectible[i]);
		i++;
	}
}

void	destroy_images(t_data *data)
{
	if (data->img_inactive_exit)
		mlx_destroy_image(data->mlx, data->img_inactive_exit);
	if (data->img_active_exit)
		mlx_destroy_image(data->mlx, data->img_active_exit);
	if (data->img_floor)
		mlx_destroy_image(data->mlx, data->img_floor);
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
	destroy_frames(data);
}

void	failure_close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	destroy_images(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data);
	free_map_cpy(data);
	exit(1);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	destroy_images(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data);
	free_map_cpy(data);
	exit(0);
}
