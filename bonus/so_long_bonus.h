/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:02:54 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/17 14:56:40 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../GNL/get_next_line.h"
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080

typedef struct s_player
{
	int			x;
	int			y;
	int			previous_x;
	int			previous_y;
}				t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img_floor;
	void		*img_wall;
	void		*img_up[4];
	void		*img_down[4];
	void		*img_left[4];
	void		*img_right[4];
	void		**img_player;
	void		*img_enemy_up[4];
	void		*img_enemy_down[4];
	void		*img_enemy_left[4];
	void		*img_enemy_right[4];
	void		*img_collectible[4];
	void		*img_inactive_exit;
	void		*img_active_exit;
	int			tile_size;
	char		**map;
	char		**map_cpy;
	size_t		width;
	size_t		height;
	size_t		total_collectibles;
	size_t		crystals_collected;
	t_player	player;
	int			player_moves;
	int			current_frame;
	int			frame_delay;
	int			enemy_move_delay;
	int			player_current_move;
}				t_data;

void			load_map(char *map_path, t_data *data);
void			check_map(t_data *data);
size_t			free_map(t_data *data);
size_t			check_characters(t_data *data);
size_t			check_lines(t_data *data);
size_t			check_path(t_data *data);
size_t			check_walls(t_data *data);
int				render_map(t_data *data);
int				close_window(t_data *data);
int				handle_key(int keycode, t_data *data);
void			move_up(t_data *data);
void			move_down(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);
void			enemy_victory(t_data *data);
void			move_enemies(t_data *data);
size_t			create_map_copy(t_data *data);
size_t			free_map_cpy(t_data *data);
void			init_map_cpy(t_data *data);
void			load_player_frames1(t_data *data);
void			load_player_frames2(t_data *data);
void			load_enemy_frames1(t_data *data);
void			load_enemy_frames2(t_data *data);
void			load_crystal_frames(t_data *data);
void			destroy_images(t_data *data);
void 			failure_close_window(t_data *data);


char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memset(void *b, int c, size_t len);

#endif
