/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:45:17 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/19 15:18:07 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <fcntl.h>
// # include "mac_mlx/mlx.h"
# include "linux_mlx/mlx.h"
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"

# define WALL	'1'
# define FLOOR	'0'
# define EXIT	'E'
# define PLAYER	'P'
# define COIN	'C'
# define TILE	64
# define EF		EXIT_FAILURE
# define ES 	EXIT_SUCCESS

typedef struct s_parsemap
{
	int			fd;
	int			emptyline;
	char		*line;
	char		**parsed_map;
	char		**copy_map;
	int			rows;
	int			columns;
	int			player;
	int			coin;
	int			exit;
	int			coin_dup;
	int			exit_dup;
	int			tile;
	int			x;
	int			y;
	int			x_exit;
	int			y_exit;
}				t_parsemap;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			moves;
	int			direction;
	int			exitflag;
	void		*sprites[5];
	t_parsemap	*map;
}				t_game;

# ifdef __APPLE__

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

# else

typedef enum s_keys
{
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363,
	LEFT = 65361,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	ESC = 65307
}	t_keys;
# endif
// game functions
void	init_map(t_game *game);
void	imglist(void);
int	moves_on_screen(t_game *game);
void	render_elements(t_game *game);
void	render_edges(t_game *game);
void	render_map(t_game *game);
int		key_checker(int key, t_game *game);

// parsing functions
void	check_char(t_parsemap *map, char c);
void	check_size(t_game *game);
void	check_tokens(t_parsemap *map);
int		check_closed(char *row, char c);
void	linecount(char *path, t_parsemap *map);
void	validate_path(char *path, t_parsemap *map);
void	map_borders(t_parsemap *map);
void	get_map(char *path, t_parsemap *map);
void	pathfinder(char **copy, int x, int y, t_parsemap *map);
void	init_tiles(t_game *game);

// cleanup functions
int		destroy_window(t_game *game);
void	free_maps(char **parsed_map, char **copy_map, t_parsemap *map);
void	free_sprites(t_game *game);
int		end_game(t_game *game);
void	destroy_map(t_parsemap *map);

// debug functions
void	print_map(t_game *game);
void	print_dup(t_game *game);
void	debug(t_game *game);

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
