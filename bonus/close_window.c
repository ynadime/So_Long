#include "so_long_bonus.h"

void	destroy_images(t_data *data)
{
	
	int i;
	mlx_destroy_image(data->mlx, data->img_inactive_exit);
	mlx_destroy_image(data->mlx, data->img_active_exit);
	mlx_destroy_image(data->mlx, data->img_floor);
	mlx_destroy_image(data->mlx, data->img_wall);
	i = 0;
	while(i < 4)
	{
		
		mlx_destroy_image(data->mlx, data->img_up[i]);
		mlx_destroy_image(data->mlx, data->img_down[i]);
		mlx_destroy_image(data->mlx, data->img_left[i]);
		mlx_destroy_image(data->mlx, data->img_right[i]);
		mlx_destroy_image(data->mlx, data->img_enemy_up[i]);
		mlx_destroy_image(data->mlx, data->img_enemy_down[i]);
		mlx_destroy_image(data->mlx, data->img_enemy_left[i]);
		mlx_destroy_image(data->mlx, data->img_enemy_right[i]);
		mlx_destroy_image(data->mlx, data->img_collectible[i]);
		i++;


	}

}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	destroy_images(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data);
	free_map_cpy(data);
	exit(0);
}