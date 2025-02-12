#include "so_long.h"

void	create_window(t_data *data)
{
	data->tile_size = 64;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width * data->tile_size,
			data->height * data->tile_size, "So long");
}

size_t	load_images(t_data *data)
{
	data->img_floor = mlx_xpm_file_to_image(data->mlx, "assets/floor.xpm",
			&data->tile_size, &data->tile_size);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm",
			&data->tile_size, &data->tile_size);
	data->img_collectible = mlx_xpm_file_to_image(data->mlx, "assets/crystal.xpm",
			&data->tile_size, &data->tile_size);
	data->img_player = mlx_xpm_file_to_image(data->mlx, "assets/player.xpm",
			&data->tile_size, &data->tile_size);
	data->img_inactive_exit = mlx_xpm_file_to_image(data->mlx, "assets/idoor.xpm",
		&data->tile_size, &data->tile_size);
	data->img_active_exit = mlx_xpm_file_to_image(data->mlx, "assets/adoor.xpm",
		&data->tile_size, &data->tile_size);	
	if (!(data->img_floor || data->img_wall || data->img_collectible
			|| data->img_player))
		return (1);
	return (0);
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
	t_data data;

	data.crystals_collected = 0;
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
	render_map(&data);
	data.player_moves = 0;
	mlx_key_hook(data.win, handle_key, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
}