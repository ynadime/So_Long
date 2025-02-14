/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:11:28 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/13 12:11:30 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	check_lines(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map[i] && data->map[i + 1])
	{
		if (ft_strlen(data->map[i]) != ft_strlen(data->map[i + 1]))
			return (ft_printf("Error\nYour map must be rectangular!"),
				free_map(data));
		i++;
	}
	data->width = ft_strlen(data->map[0]);
	return (0);
}
