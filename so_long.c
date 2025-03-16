/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:21:52 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/16 04:02:20 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(char *path, t_game *game)
{
	init_vars(&game->map);
	validate_path(path, &game->map);
	get_map(path, &game->map);
	check_size(&game->map);
	map_borders(&game->map);
	check_tokens(&game->map);
	if (game->map.player != 1 || game->map.exit != 1 || game->map.coin < 1)
	{
		ft_putstr_fd("ERROR: Wrong number of tokens.\n", 2);
		(free_maps(game->map.parsed_map, game->map.copy_map, &game->map), exit(EF));
	}
	pathfinder(game->map.copy_map, game->map.x, game->map.y, &game->map);
	if (game->map.coin_dup != 0 || game->map.exit_dup != 0)
	{
		ft_putstr_fd("ERROR: Invalid path.\n", 2);
		(free_maps(game->map.parsed_map, game->map.copy_map, &game->map), exit(EF));
	}
	free_maps(NULL, game->map.copy_map, NULL);
}

int	main(int ac, char **av)
{
	t_game	game;
	
	game.moves = 0;
	game.direction = 0;
	imglist();
	game.map = malloc(sizeof(t_parsemap));
	if (ac != 2)
		(ft_putstr_fd ("ERROR: Try ./so_long [Map].ber.\n", 2), exit(EF));
	parse_map(av[1], &game);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.map.columns * TILE,
			game.map.rows * TILE, "so_long");
	render_map(&game);
	mlx_hook(game.window, 2, 0, keys, &game);
	mlx_hook(game.window, 17, 0, end_game, &game);
	mlx_loop_hook(game.mlx, exit_check, &game);
	// * keys
	// * exit
	mlx_loop(game.mlx);
	return (0);
}
