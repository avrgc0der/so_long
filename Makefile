# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 12:27:36 by tabadawi          #+#    #+#              #
#    Updated: 2025/03/06 12:14:12 by enoshahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long

CFLAGS  = -Wall -Werror -Wextra
# u cud use this later
# CFLAGS	+= -fsanitize=address -g3

RM      = rm -f

SRCS    = so_long.c debug.c message.c free.c map.c

OBJ     = $(SRCS:.c=.o)

LIBFT    = libft/libft.a

PRINTF	 = libft/ft_printf/libftprintf.a

MLX      = linux_mlx/libmlx.a
# MLX      = mac_mlx/libmlx.a

# linux
MLXFLAG = -L linux_mlx -lmlx -lXext -lX11 -lm -lGL

# mac
# MLXFLAG	=	-L mac_mlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(LIBFT):
	$(MAKE)	-C libft

$(PRINTF):
	$(MAKE)	-C libft/ft_printf

# $(MLX):
# 	$(MAKE)	-C mac_mlx
$(MLX):
	$(MAKE)	-C linux_mlx

$(NAME): $(OBJ) $(LIBFT) $(MLX) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAG) -o $@ $(LIBFT) $(MLX) $(PRINTF)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C libft clean
	$(MAKE) -C libft/ft_printf clean

fclean: clean
	$(RM) $(OBJ)
	$(MAKE) -C libft fclean
	$(MAKE) -C libft/ft_printf fclean
	$(MAKE) -C linux_mlx clean
	$(RM) $(NAME)
	
# $(MAKE) -C mac_mlx clean
# $(MAKE) -C linux_mlx clean

re: fclean all

.PHONY: all clean fclean re 