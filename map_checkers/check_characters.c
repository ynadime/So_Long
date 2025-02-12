#include "../so_long.h"

size_t	check_invalid_characters(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] != '0' && data->map[y][x] != '1'
				&& data->map[y][x] != 'C' && data->map[y][x] != 'E'
				&& data->map[y][x] != 'P')
			{
				ft_printf("Error\n");
				ft_printf("Invalid character found at (%i,%i)", x, y);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

size_t	check_collectibles(t_data *data)
{
	size_t	collectibles;
	size_t	x;
	size_t	y;

	y = 0;
	collectibles = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				collectibles++;
			x++;
		}
		y++;
	}
	if (collectibles < 1)
		return (ft_printf("Error\nNo crystals were found on the map!"), 1);
	data->total_collectibles = collectibles;
	return (0);
}

size_t	check_exit(t_data *data)
{
	size_t	exit;
	size_t	x;
	size_t	y;

	y = 0;
	exit = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E')
				exit++;
			x++;
		}
		y++;
	}
	if (exit != 1)
		return (ft_printf("Error\nInvalid number of exits!"), 1);
	else
		return (0);
}

size_t	check_player(t_data *data)
{
	size_t	player;
	size_t	x;
	size_t	y;

	y = 0;
	player = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
				player++;
			}
			x++;
		}
		y++;
	}
	if (player != 1)
		return (ft_printf("Error\nInvalid number of players!"), 1);
	else
		return (0);
}

size_t	check_characters(t_data *data)
{
	if (check_invalid_characters(data) || check_player(data)
		|| check_collectibles(data) || check_exit(data))
		return (free_map(data));
	return (0);
}
