/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:29:45 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/19 14:18:25 by enoshahi         ###   ########.fr       */
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
	free_maps(game->map->parsed_map, NULL, game->map);
	free_sprites(game);
	mlx_destroy_window(game->mlx, game->window);
	exit(ES);
}

void	free_maps(char **parsed_map, char **copy_map, t_parsemap *map)
{
	int	i;

	i = -1;
	if (parsed_map)
	{
		while (parsed_map[++i])
			free(parsed_map[i]);
		free(parsed_map);
	}
	i = -1;
	if (copy_map)
	{
		while (copy_map[++i])
			free(copy_map[i]);
		free(copy_map);
	}
	if (map)
		// free(map);
		destroy_map(map);
}

void	destroy_map(t_parsemap *map)
{
	int	row;

	row = 0;
	while (map->parsed_map[row])
	{
		free(map->parsed_map[row]);
		row++;
	}
}

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	(free_maps(game->map->parsed_map,
			game->map->copy_map, game->map), exit(EF));
	// free game struct
	exit(1);
}
