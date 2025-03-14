/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:28:52 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/18 12:28:55 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	flood_fill(t_data *data, int x, int y, char **map_cpy)
{
	if (x < 0 || y < 0 || x >= (int)data->width || y >= (int)data->height)
		return ;
	if (data->map[y][x] == '1' || data->map_cpy[y][x] == 'X')
		return ;
	if (data->map[y][x] == 'E')
	{
		data->map_cpy[y][x] = 'X';
		return ;
	}
	map_cpy[y][x] = 'X';
	flood_fill(data, x, y - 1, data->map_cpy);
	flood_fill(data, x, y + 1, data->map_cpy);
	flood_fill(data, x - 1, y, data->map_cpy);
	flood_fill(data, x + 1, y, data->map_cpy);
}

size_t	check_if_reachable(t_data *data)
{
	int	x;
	int	y;

	flood_fill(data, data->player.x, data->player.y, data->map_cpy);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E' && data->map_cpy[y][x] != 'X')
			{
				ft_printf("Error\nThe exit at (%i,%i) is unreachable!", x, y);
				return (free_map_cpy(data));
			}
			if (data->map[y][x] == 'C' && data->map_cpy[y][x] != 'X')
			{
				ft_printf("Error\nCrystal at (%i,%i) is unreachable!", x, y);
				return (free_map_cpy(data));
			}
			x++;
		}
		y++;
	}
	return (0);
}

size_t	check_path(t_data *data)
{
	data->map_cpy = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (!data->map_cpy)
		return (perror("Error\n"), 1);
	if (create_map_copy(data))
		return (free_map(data));
	if (check_if_reachable(data))
		return (free_map(data));
	return (0);
}
