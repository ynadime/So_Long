#include "so_long.h"

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
	if(data->width * data->tile_size > 1920 || data->height * data->tile_size > 1080)
	{
		ft_printf("Error\nYour map must not exceed the resolution of 1920x1080");
		free_map(data);
		exit(1);
	}
}
