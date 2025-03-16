# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 12:27:36 by tabadawi          #+#    #+#              #
#    Updated: 2025/03/14 20:39:09 by enoshahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long

CFLAGS  = -Wall -Werror -Wextra
# u cud use this later
# CFLAGS	+= -fsanitize=address -g3

RM      = rm -f

SRCS    = so_long.c debug.c free.c map.c images.c keys.c path.c utils.c window.c

OBJ     = $(SRCS:.c=.o)

LIBFT    = libft/libft.a

FT_PRINTF	 = libft/ft_printf/libftprintf.a

GNL			= libft/get_next_line/get_next_line.a

MLX      = linux_mlx/libmlx.a
# MLX      = mac_mlx/libmlx.a

# linux
MLXFLAG = -L linux_mlx -lmlx -lXext -lX11 -lm -lGL

# mac
# MLXFLAG	=	-L mac_mlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(LIBFT):
	$(MAKE)	-C libft

$(FT_PRINTF):
	$(MAKE)	-C libft/ft_printf

$(GNL):
	$(MAKE)	-C libft/get_next_line


# $(MLX):
# 	$(MAKE)	-C mac_mlx
$(MLX): $(MLX) 
	$(MAKE)	-C linux_mlx

$(NAME): $(OBJ) $(LIBFT) $(MLX) $(FT_PRINTF) $(GNL)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAG) -o $@ $(LIBFT) $(MLX) $(FT_PRINTF) $(GNL)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C libft clean
	$(MAKE) -C libft/ft_printf clean
	$(MAKE) -C libft/get_next_line clean

fclean: clean
	$(RM) $(OBJ)
	$(MAKE) -C libft fclean
	$(MAKE) -C libft/ft_printf fclean
	$(MAKE) -C libft/get_next_line clean
	$(MAKE) -C linux_mlx clean
	$(RM) $(NAME)
	
# $(MAKE) -C mac_mlx clean
# $(MAKE) -C linux_mlx clean

re: fclean all

.PHONY: all clean fclean re 