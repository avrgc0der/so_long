/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:45:17 by enoshahi          #+#    #+#             */
/*   Updated: 2025/02/28 20:25:06 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

# define WALL	'1'
# define FLOOR	'0'
# define EXIT	'E'
# define PLAYER	'P'
# define COIN	'C'

typedef struct s_player
{
	int	x;
	int	y;
	int	movement;
}		t_player;

typedef struct s_checks
{
	int	coin;
	int	coin_dup;
	int	player;
	int	exit;
	int	exit_dup;
}		t_checks;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		**parsed_map;
	char		**copy_map;
	void		*imgs[5];
	int			map_width;
	int			map_height;
	t_player	player;
	t_checks	checks;
}				t_game;

typedef enum s_keys
{
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESC = 53
}	t_keys;

// game functions
void	initializer(t_game *game);

// parsing functions

// cleanup functions
int		destroy_window(t_game *game);

// extra functions
void	message(char *msg, t_game *game);

// debug functions
void	print_map(t_game *game);
void	print_dup(t_game *game);
void	print_data(t_game *game);

#endif


// requirements

// map file is in correct format/extension
	// oend of file is .ber

// map file is openable and not empty
	// open doesnt return -1

// retrieve map
	// check that file has content
	// gnl the whole file
	// remove \n char
	// create duplicate (copy)

// map size is correct
	// rectangular
	// minimum is 3*5

// map is closed
	// borders are all '1'

// map has no invalid chars
	// valid chars are 1, 0, P, C, E

// map has correct count of characters
	// at least 1 coin
	// 1 exit
	// 1 player

// valid path
	// flood fill
