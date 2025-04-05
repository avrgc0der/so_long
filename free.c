/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:29:45 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/05 17:45:22 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprites[0]);
	mlx_destroy_image(game->mlx, game->sprites[1]);
	mlx_destroy_image(game->mlx, game->sprites[2]);
	mlx_destroy_image(game->mlx, game->sprites[3]);
	mlx_destroy_image(game->mlx, game->sprites[4]);
}

int	end_game(t_game *game)
{
	ft_printf("Game over.\n");
	free_maps(game->map->prsd, game->map->copy, game->map);
	free_sprites(game);
	mlx_destroy_window(game->mlx, game->window);
	exit(ES);
}

void	free_map(char **map)
{
	int	row;

	row = 0;
	while (map[row])
	{
		free(map[row]);
		map[row] = NULL;
		row++;
	}
	free(map);
	map = NULL;
}

void	free_maps(char **prsd, char **copy, t_parsemap *map)
{
	if (prsd)
		free_map(prsd);
	if (copy)
		free_map(copy);
	free(map);
}

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	(free_maps(game->map->prsd,
			game->map->copy, game->map), exit(ES));
	exit(1);
}
