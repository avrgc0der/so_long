# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 12:27:36 by tabadawi          #+#    #+#              #
#    Updated: 2025/04/05 17:46:42 by tabadawi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long

CFLAGS  = -Wall -Werror -Wextra -g3
# u cud use this later
# CFLAGS	+= -fsanitize=address -g3

RM      = rm -f

SRCS    = so_long.c free.c map.c path.c utils.c images.c keys.c render.c

OBJ     = $(SRCS:.c=.o)

LIBFT    = libft/libft.a

FT_PRINTF	 = libft/ft_printf/libftprintf.a

GNL			= libft/get_next_line/get_next_line.a

MLX      = mac_mlx/libmlx.a
MLXFLAG	=	-L mac_mlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(LIBFT):
	$(MAKE)	-C libft

$(FT_PRINTF):
	$(MAKE)	-C libft/ft_printf

$(GNL):
	$(MAKE)	-C libft/get_next_line

$(MLX):
	$(MAKE)	-C mac_mlx

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
	$(MAKE) -C libft/get_next_line fclean
	$(MAKE) -C mac_mlx clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 