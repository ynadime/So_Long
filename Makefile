# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynadime <ynadime@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 12:10:16 by ynadime           #+#    #+#              #
#    Updated: 2025/02/14 15:50:40 by ynadime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c \
      render_map.c \
      player_moves.c \
      load_map.c \
      handle_key.c \
      close_window.c \
      check_map.c \
      utils/ft_memset.c \
      utils/ft_strlcpy.c \
      utils/ft_strlen.c \
      utils/ft_strncmp.c \
      utils/ft_strtrim.c \
      printf/ft_printf.c \
      printf/ft_printf_utils.c \
      map_checkers/check_characters.c \
      map_checkers/check_lines.c \
      map_checkers/check_path.c \
      map_checkers/check_walls.c \
      GNL/get_next_line.c \
      GNL/get_next_line_utils.c

Bonus_SRC = bonus/main.c \
      bonus/render_map.c \
      bonus/player_moves.c \
      bonus/load_map.c \
      bonus/handle_key.c \
      bonus/close_window.c \
      bonus/check_map.c \
      bonus/utils/ft_memset.c \
      bonus/utils/ft_strlcpy.c \
      bonus/utils/ft_strlen.c \
      bonus/utils/ft_strncmp.c \
      bonus/utils/ft_strtrim.c \
      bonus/utils/ft_itoa.c \
      printf/ft_printf.c \
      printf/ft_printf_utils.c \
      bonus/map_copy.c \
      bonus/map_checkers/check_characters.c \
      bonus/map_checkers/check_lines.c \
      bonus/map_checkers/check_path.c \
      bonus/map_checkers/check_walls.c \
      bonus/enemy_victory.c \
      bonus/move_enemies.c \
      bonus/load_frames.c \
      GNL/get_next_line.c \
      GNL/get_next_line_utils.c

OBJS = $(SRC:.c=.o)

Bonus_OBJS = $(Bonus_SRC:.c=.o)

MLX = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

bonus: $(Bonus_OBJS)
	$(CC) $(CFLAGS) $(Bonus_OBJS) $(MLX) -o $(NAME)
      
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(Bonus_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
