/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:09:16 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/17 13:43:40 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_data *data)
{
	if (data->img_collectible)
		mlx_destroy_image(data->mlx, data->img_collectible);
	if (data->img_inactive_exit)
		mlx_destroy_image(data->mlx, data->img_inactive_exit);
	if (data->img_active_exit)
		mlx_destroy_image(data->mlx, data->img_active_exit);
	if (data->img_floor)
		mlx_destroy_image(data->mlx, data->img_floor);
	if (data->img_player)
		mlx_destroy_image(data->mlx, data->img_player);
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
}

void	failure_close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	destroy_images(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data);
	exit(1);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	destroy_images(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data);
	exit(0);
}
