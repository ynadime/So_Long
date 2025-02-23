/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:10:32 by ynadime           #+#    #+#             */
/*   Updated: 2025/02/22 21:08:34 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "GNL/get_next_line.h"
# include "printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img_floor;
	void		*img_wall;
	void		*img_player;
	void		*img_collectible;
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
}				t_data;

void			load_map(char *map_path, t_data *data);
void			check_map(t_data *data);
size_t			free_map(t_data *data);
size_t			check_characters(t_data *data);
size_t			check_lines(t_data *data);
size_t			check_path(t_data *data);
size_t			check_walls(t_data *data);
void			render_map(t_data *data);
int				close_window(t_data *data);
void			failure_close_window(t_data *data);

int				handle_key(int keycode, t_data *data);
void			move_up(t_data *data);
void			move_down(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memset(void *b, int c, size_t len);

#endif
