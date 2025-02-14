/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:03:07 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/13 20:55:48 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_enemy_pose(t_data *data, int x, int y, char direction)
{
	if (direction == 'U')
	{
		data->map[y - 1][x] = 'F';
		data->map[y][x] = '0';
		data->map_cpy[y - 1][x] = 'U';
	}
	else if (direction == 'D')
	{
		data->map[y + 1][x] = 'F';
		data->map[y][x] = '0';
		data->map_cpy[y + 1][x] = 'D';
	}
	else if (direction == 'L')
	{
		data->map[y][x - 1] = 'F';
		data->map[y][x] = '0';
		data->map_cpy[y][x - 1] = 'L';
	}
	else if (direction == 'R')
	{
		data->map[y][x + 1] = 'F';
		data->map[y][x] = '0';
		data->map_cpy[y][x + 1] = 'R';
	}
}

void	handle_enemy_movment(t_data *data, int x, int y)
{
	if (y > data->player.y && data->map[y - 1][x] == '0')
		update_enemy_pose(data, x, y, 'U');
	else if (x < data->player.x && data->map[y][x + 1] == '0')
		update_enemy_pose(data, x, y, 'R');
	else if (y < data->player.y && data->map[y + 1][x] == '0')
		update_enemy_pose(data, x, y, 'D');
	else if (x > data->player.y && data->map[y][x - 1] == '0')
		update_enemy_pose(data, x, y, 'L');
	else if (data->map[y - 1][x] == '0')
		update_enemy_pose(data, x, y, 'U');
	else if (data->map[y][x + 1] == '0')
		update_enemy_pose(data, x, y, 'R');
	else if (data->map[y + 1][x] == '0')
		update_enemy_pose(data, x, y, 'D');
	else if (data->map[y][x - 1] == '0')
		update_enemy_pose(data, x, y, 'L');
}

void	enemy_win_move(t_data *data, int x, int y, char direction)
{
	if (direction == 'U')
		update_enemy_pose(data, x, y, 'U');
	else if (direction == 'D')
		update_enemy_pose(data, x, y, 'D');
	else if (direction == 'L')
		update_enemy_pose(data, x, y, 'L');
	else if (direction == 'R')
		update_enemy_pose(data, x, y, 'R');
	enemy_victory(data);
}

void	make_enemy_move(t_data *data, int x, int y)
{
	if (data->map[y - 1][x] == 'P')
		enemy_win_move(data, x, y, 'U');
	else if (data->map[y + 1][x] == 'P')
		enemy_win_move(data, x, y, 'D');
	else if (data->map[y][x - 1] == 'P')
		enemy_win_move(data, x, y, 'L');
	else if (data->map[y][x + 1] == 'P')
		enemy_win_move(data, x, y, 'R');
	else if (data->map[y - 1][x] == '0' && y - 1 == data->player.previous_y
		&& x == data->player.previous_x)
		update_enemy_pose(data, x, y, 'U');
	else if (data->map[y + 1][x] == '0' && y + 1 == data->player.previous_y
		&& x == data->player.previous_x)
		update_enemy_pose(data, x, y, 'D');
	else if (data->map[y][x - 1] == '0' && y == data->player.previous_y && x
		- 1 == data->player.previous_x)
		update_enemy_pose(data, x, y, 'L');
	else if (data->map[y][x + 1] == '0' && y == data->player.previous_y && x
		+ 1 == data->player.previous_x)
		update_enemy_pose(data, x, y, 'R');
	else
		handle_enemy_movment(data, x, y);
}

void	move_enemies(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	init_map_cpy(data);
	while (y < (int)data->height)
	{
		x = 0;
		while (x < (int)data->width)
		{
			if (data->map[y][x] == 'F' && data->map_cpy[y][x] == 'O')
				make_enemy_move(data, x, y);
			x++;
		}
		y++;
	}
}
