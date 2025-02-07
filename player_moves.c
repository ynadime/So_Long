#include "so_long.h"

void	move_player(t_data *data, int x, int y)
{
	if (data->map[data->player_y + y][data->player_x + x] != '1')
	{
		if (data->map[data->player_y + y][data->player_x + x] == 'E')
		{
			if (data->chests_collected != data->total_collectibles)
				return ;
			data->player_moves++;
			printf("Game over, you won!");
			close_window(data);
			exit(0);
		}
		else if (data->map[data->player_y + y][data->player_x + x] == 'C')
			data->chests_collected++;
		data->map[data->player_y + y][data->player_x + x] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		data->player_x += x;
		data->player_y += y;
		data->player_moves++;
		render_map(data);
		ft_printf("Player move count = %i\nChests collected %i/%i\n",
					data->player_moves,
					data->chests_collected,
					data->total_collectibles);
	}
}

void	move_up(t_data *data)
{
	move_player(data, 0, -1);
}
void	move_down(t_data *data)
{
	move_player(data, 0, +1);
}
void	move_left(t_data *data)
{
	move_player(data, -1, 0);
}
void	move_right(t_data *data)
{
	move_player(data, +1, 0);
}