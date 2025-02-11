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

}
