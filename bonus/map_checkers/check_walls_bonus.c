/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:28:59 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/18 12:29:00 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

size_t	check_walls(t_data *data)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < data->width)
	{
		if (data->map[0][x] != '1' || data->map[data->height - 1][x] != '1')
		{
			ft_printf("Error\nYour map must be surrounded by walls!");
			return (free_map(data));
		}
		x++;
	}
	while (y < data->height)
	{
		if (data->map[y][0] != '1' || data->map[y][data->width - 1] != '1')
		{
			ft_printf("Error\nYour map must be surrounded by walls!");
			return (free_map(data));
		}
		y++;
	}
	return (0);
}
