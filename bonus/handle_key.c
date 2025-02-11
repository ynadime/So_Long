#include "so_long_bonus.h"

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

int	handle_key(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_window(data);
	if (keycode == KEY_W)
		move_up(data);
	if (keycode == KEY_S)
		move_down(data);
	if (keycode == KEY_A)
		move_left(data);
	if (keycode == KEY_D)
		move_right(data);

	return (0);
}