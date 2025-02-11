#include "so_long_bonus.h"

void put_enemy_image_to_window(t_data *data, int x, int y)
{
	if(data->map_cpy[y][x] == 'D' || data->map_cpy[y][x] == 'O' )
	mlx_put_image_to_window(data->mlx, data->win, data->img_enemy_down[data->current_frame], x
	* data->tile_size, y * data->tile_size);
	else if(data->map_cpy[y][x] == 'U' )
	mlx_put_image_to_window(data->mlx, data->win, data->img_enemy_up[data->current_frame], x
	* data->tile_size, y * data->tile_size);
		else if(data->map_cpy[y][x] == 'R' )
	mlx_put_image_to_window(data->mlx, data->win, data->img_enemy_right[data->current_frame], x
	* data->tile_size, y * data->tile_size);
	else if(data->map_cpy[y][x] == 'L' )
	mlx_put_image_to_window(data->mlx, data->win, data->img_enemy_left[data->current_frame], x
	* data->tile_size, y * data->tile_size);



}

void put_image_to_window(t_data *data, int x, int y)
{
	if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img_floor, x
						* data->tile_size, y * data->tile_size);
	else if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img_wall, x
						* data->tile_size, y * data->tile_size);
	else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
						data->img_collectible[data->current_frame], x * data->tile_size, y
						* data->tile_size);
	else if (data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->img_player[data->player_current_move],
						x * data->tile_size, y * data->tile_size);
	else if (data->map[y][x] == 'E')
	{
		if(data->total_collectibles == data->crystals_collected)
		mlx_put_image_to_window(data->mlx, data->win, data->img_active_exit, x
		* data->tile_size, y * data->tile_size);
		else
		mlx_put_image_to_window(data->mlx, data->win, data->img_inactive_exit, x
		* data->tile_size, y * data->tile_size);
	}
	else if (data->map[y][x] == 'F')
	put_enemy_image_to_window(data, x, y);

}

int	render_map(t_data *data)
{
	size_t x;
	size_t y;
	data->frame_delay++;
	data->enemy_move_delay++;


	if(data->frame_delay == 25)
	{
		data->current_frame = (data->current_frame + 1 ) % 4;
		data->frame_delay = 0;
	}
	if(data->enemy_move_delay == 150)
	{
		move_enemies(data);
		data->enemy_move_delay = 0;
	}


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
	return (0);
}