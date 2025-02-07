#include "so_long.h"

void	render_map(t_data *data)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img_floor, x
						* data->tile_size, y * data->tile_size);
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img_wall, x
						* data->tile_size, y * data->tile_size);
			if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
						data->img_collectible, x * data->tile_size, y
						* data->tile_size);
			if (data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->img_player,
						x * data->tile_size, y * data->tile_size);
			if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img_exit, x
						* data->tile_size, y * data->tile_size);
			x++;
		}
		y++;
	}
}