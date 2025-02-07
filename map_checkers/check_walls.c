#include "../so_long.h"

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
			printerr("Error\nYour map must be surrounded by walls!");
			return (1);
		}
		x++;
	}
	while (y < data->height)
	{
		if (data->map[y][0] != '1' || data->map[y][data->width - 1] != '1')
		{
			printerr("Error\nYour map must be surrounded by walls!");
			return (1);
		}
		y++;
	}
	return (0);
}
