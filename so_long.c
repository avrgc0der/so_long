/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:21:52 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/05 18:32:35 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_path(char *path, t_parsemap *map)
{
	int	fd;

	if (!path)
		clean_exit(NULL, "ERROR: No such path.\nTry\
		./so_long [Map].ber\n", map);
	if (ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 4) != 0)
		clean_exit(NULL, "ERROR: Wrong extension.\nTry \
		./so_long [Map].ber\n", map);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		clean_exit(NULL, "ERROR: No file exists.\n", map);
	close(fd);
}

void	parse_map(char *path, t_game *game)
{
	validate_path(path, game->map);
	get_map(path, game->map, game);
	check_size(game);
	map_borders(game->map, game);
	check_tokens(game->map);
	if (game->map->player != 1 || game->map->exit != 1 || game->map->coin < 1)
		clean_exit(game, "ERROR: Wrong number of tokens.\n", NULL);
	find_exit(game);
	pathfinder(game->map->copy, game->map->x, game->map->y, game->map);
	if (game->map->coin_dup != 0 || game->map->exit_dup != 0)
		clean_exit(game, "ERROR: Invalid path.\n", NULL);
}

void	init_game(t_game *game)
{
	game->direction = 0;
	game->exitflag = -1;
	game->moves = 0;
	game->map = malloc(sizeof(t_parsemap));
	init_map(game);
}

void	find_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->rows)
	{
		j = 0;
		while (j < game->map->columns)
		{
			if (game->map->prsd[i][j] == EXIT)
			{
				game->map->x_exit = j;
				game->map->y_exit = i;
				game->map->copy[i][j] = WALL;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_putstr_fd ("ERROR: Try ./so_long [Map].ber.\n", 2);
		exit(EF);
	}
	init_game(&game);
	imglist();
	parse_map(av[1], &game);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.map->columns * TILE,
			game.map->rows * TILE, "so_long");
	render_map(&game);
	mlx_hook(game.window, 2, 0, key_checker, &game);
	mlx_hook(game.window, 17, 0, end_game, &game);
	mlx_loop_hook(game.mlx, moves_on_screen, &game);
	mlx_loop(game.mlx);
	end_game(&game);
	return (0);
}
