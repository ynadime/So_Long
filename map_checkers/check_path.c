#include "../so_long.h"

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

size_t	copy_map(t_data *data)
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

	flood_fill(data, data->player_x, data->player_y, data->map_cpy);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E' && data->map_cpy[y][x] != 'X')
			{
				printerr("Error\nThe exit at (%i,%i) is unreachable!", x, y);
				return (free_map_cpy(data));
			}
			if (data->map[y][x] == 'C' && data->map_cpy[y][x] != 'X')
			{
				printerr("Error\nThe chest at (%i,%i) is unreachable!", x, y);
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
	if (copy_map(data))
		return (free_map(data));
	if (check_if_reachable(data))
		return (free_map(data));
	free_map_cpy(data);
	return (0);
}
