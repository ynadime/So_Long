/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:02:29 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/13 19:02:31 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map(t_data *data)
{
	if (check_lines(data))
		exit(1);
	if (check_walls(data))
		exit(1);
	if (check_characters(data))
		exit(1);
	if (check_path(data))
		exit(1);
	if (data->width * data->tile_size > MAX_WIDTH || data->height
		* data->tile_size > MAX_HEIGHT)
	{
		ft_printf("Error\nYour map exceeds the resolution of 1920x1080!");
		free_map(data);
		free_map_cpy(data);
		exit(1);
	}
}
