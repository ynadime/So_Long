/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:14:28 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/17 14:56:44 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_player(t_data *data, int x, int y)
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
	data->player.previous_x = data->player.x;
	data->player.previous_y = data->player.y;
	data->player.x += x;
	data->player.y += y;
	data->player_moves++;
	data->player_current_move = (data->player_current_move + 1) % 4;
}

void	move_up(t_data *data)
{
	if (data->map[data->player.y - 1][data->player.x] == 'F')
		enemy_victory(data);
	else if (data->map[data->player.y - 1][data->player.x] != '1')
	{
		data->img_player = data->img_up;
		move_player(data, 0, -1);
	}
}

void	move_down(t_data *data)
{
	if (data->map[data->player.y + 1][data->player.x] == 'F')
		enemy_victory(data);
	else if (data->map[data->player.y + 1][data->player.x] != '1')
	{
		data->img_player = data->img_down;
		move_player(data, 0, +1);
	}
}

void	move_left(t_data *data)
{
	if (data->map[data->player.y][data->player.x - 1] == 'F')
		enemy_victory(data);
	if (data->map[data->player.y][data->player.x - 1] != '1')
	{
		data->img_player = data->img_left;
		move_player(data, -1, 0);
	}
}

void	move_right(t_data *data)
{
	if (data->map[data->player.y][data->player.x + 1] == 'F')
		enemy_victory(data);
	else if (data->map[data->player.y][data->player.x + 1] != '1')
	{
		data->img_player = data->img_right;
		move_player(data, +1, 0);
	}
}
