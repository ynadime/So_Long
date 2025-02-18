/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:30:20 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/18 12:30:21 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_map_cpy(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map[i])
	{
		ft_memset(data->map_cpy[i], 'O', data->width);
		i++;
	}
}

size_t	free_map_cpy(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map_cpy[i])
	{
		free(data->map_cpy[i]);
		i++;
	}
	free(data->map_cpy);
	return (1);
}

size_t	create_map_copy(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->height)
	{
		data->map_cpy[i] = (char *)malloc(sizeof(char) * (data->width + 1));
		if (!data->map_cpy[i])
			return (perror("Error\n"), free_map_cpy(data));
		ft_memset(data->map_cpy[i], 'O', data->width);
		i++;
	}
	data->map_cpy[i] = NULL;
	return (0);
}
