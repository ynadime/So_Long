/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:09:16 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/13 12:09:18 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_collectible);
	mlx_destroy_image(data->mlx, data->img_active_exit);
	mlx_destroy_image(data->mlx, data->img_inactive_exit);
	mlx_destroy_image(data->mlx, data->img_floor);
	mlx_destroy_image(data->mlx, data->img_player);
	mlx_destroy_image(data->mlx, data->img_wall);
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
