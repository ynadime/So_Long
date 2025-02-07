NAME = So_long

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
      printerr/printerr.c \
      printerr/printerr_utils.c \
      map_checkers/check_characters.c \
      map_checkers/check_lines.c \
      map_checkers/check_path.c \
      map_checkers/check_walls.c \
      GNL/get_next_line.c \
      GNL/get_next_line_utils.c

Bonus_SRC = main.c \
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
      printerr/printerr.c \
      printerr/printerr_utils.c \
      map_checkers/check_characters.c \
      map_checkers/check_lines.c \
      map_checkers/check_path.c \
      map_checkers/check_walls.c \
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
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re