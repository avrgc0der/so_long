/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:45:17 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/05 18:32:51 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <fcntl.h>
# include "mac_mlx/mlx.h"
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
	char		**prsd;
	char		**copy;
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
void	init_map(t_game *game);
void	imglist(void);
int		moves_on_screen(t_game *game);
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
void	map_borders(t_parsemap *map, t_game *game);
void	get_map(char *path, t_parsemap *map, t_game *game);
void	pathfinder(char **copy, int x, int y, t_parsemap *map);
void	init_tiles(t_game *game);
void	find_exit(t_game *game);

// cleanup functions
int		destroy_window(t_game *game);
void	free_maps(char **prsd, char **copy, t_parsemap *map);
void	free_sprites(t_game *game);
int		end_game(t_game *game);
void	clean_exit(t_game *game, char *error, t_parsemap *map);
void	linecount_exit(t_parsemap *map, int *fd, char *error);

#endif