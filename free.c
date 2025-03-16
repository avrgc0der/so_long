/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:29:45 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/16 16:22:54 by tabadawi         ###   ########.fr       */
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

void	end_game(t_game *game)
{
	ft_printf("Game over.\n");
	free_sprites(game);
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
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
		free(map);
}
