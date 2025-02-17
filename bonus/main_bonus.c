/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:03:16 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/17 14:56:54 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_loaded_images(t_data *data)
{
	if (!data->img_collectible[0] || !data->img_collectible[1]
		|| !data->img_collectible[2] || !data->img_collectible[3]
		|| !data->img_inactive_exit || !data->img_active_exit
		|| !data->img_floor || !data->img_wall || !data->img_up[0]
		|| !data->img_up[1] || !data->img_up[2] || !data->img_up[3]
		|| !data->img_down[0] || !data->img_down[1] || !data->img_down[2]
		|| !data->img_down[3] || !data->img_left[0] || !data->img_left[1]
		|| !data->img_left[2] || !data->img_left[3] || !data->img_right[0]
		|| !data->img_right[1] || !data->img_right[2] || !data->img_right[3]
		|| !data->img_enemy_up[0] || !data->img_enemy_up[1]
		|| !data->img_enemy_up[2] || !data->img_enemy_up[3]
		|| !data->img_enemy_down[0] || !data->img_enemy_down[1]
		|| !data->img_enemy_down[2] || !data->img_enemy_down[3]
		|| !data->img_enemy_left[0] || !data->img_enemy_left[1]
		|| !data->img_enemy_left[2] || !data->img_enemy_left[3]
		|| !data->img_enemy_right[0] || !data->img_enemy_right[1]
		|| !data->img_enemy_right[2] || !data->img_enemy_right[3])
	{
		ft_printf("Error\nFailed to load images!");
		failure_close_window(data);
	}
}

void	create_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width * data->tile_size,
			data->height * data->tile_size, "So long");
}

void	load_images(t_data *data)
{
	data->img_floor = mlx_xpm_file_to_image(data->mlx, "bonus/assets/floor.xpm",
			&data->tile_size, &data->tile_size);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "bonus/assets/wall.xpm",
			&data->tile_size, &data->tile_size);
	data->img_inactive_exit = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/idoor.xpm", &data->tile_size, &data->tile_size);
	data->img_active_exit = mlx_xpm_file_to_image(data->mlx,
			"bonus/assets/adoor.xpm", &data->tile_size, &data->tile_size);
	load_crystal_frames(data);
	load_player_frames1(data);
	load_player_frames2(data);
	load_enemy_frames1(data);
	load_enemy_frames2(data);
	check_loaded_images(data);
}

size_t	free_map(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	data.tile_size = 64;
	if (ac != 2)
	{
		ft_printf("Error\nInvalid number of arguments!");
		exit(1);
	}
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".ber", 4))
	{
		ft_printf("Error\nInvalid file name!");
		exit(1);
	}
	load_map(av[1], &data);
	check_map(&data);
	create_window(&data);
	load_images(&data);
	init_map_cpy(&data);
	mlx_loop_hook(data.mlx, render_map, &data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
}
