NAME    = so_long
CFLAGS  = -Wall -Werror -Wextra
RM      = rm -rf

SRCS    = so_long.c debug.c
OBJ     = $(SRCS:.c=.o)

LIBFT    = game/libft/libft.a
MLX      = game/mlx/libmlx.a
PRINTF	 = game/libft/ft_printf/libftprintf.a

MLXFLAG = -Lmlx -lmlx -lXext -lX11 -lm -lGL

# %.o: %.c
# 	$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
	$(MAKE)	-C game/libft

$(PRINTF): $(LIBFT)
	$(MAKE)	-C game/libft/ft_printf

$(MLX):
	$(MAKE)	-C game/mlx

# Ensure get_next_line and ft_printf are compiled inside libft

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(PRINTF) $(MLXFLAG) -o $@
# $(NAME): $(OBJ)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C game/libft clean
	$(MAKE) -C game/libft/ft_printf clean

fclean: clean
	$(RM) $(OBJ)
	$(MAKE) -C game/libft fclean
	$(MAKE) -C game/libft/ft_printf fclean
	$(MAKE) -C game/mlx clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 