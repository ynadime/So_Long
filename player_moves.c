#include "so_long.h"

void	move_player(t_data *data, int x, int y)
{
	if (data->map[data->player.y + y][data->player.x + x] != '1')
	{
		if (data->map[data->player.y + y][data->player.x + x] == 'E')
		{
			if (data->crystals_collected != data->total_collectibles)
				return ;
			data->player_moves++;
			ft_printf("Game over, you won!");
			close_window(data);
			exit(0);
		}
		else if (data->map[data->player.y + y][data->player.x + x] == 'C')
			data->crystals_collected++;
		data->map[data->player.y + y][data->player.x + x] = 'P';
		data->map[data->player.y][data->player.x] = '0';
		data->player.x += x;
		data->player.y += y;
		data->player_moves++;
		ft_printf("Player move count: %i\n",data->player_moves);
		render_map(data);
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