/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:15:21 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/19 13:49:50 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *game, int new_x, int new_y)
{
	if (game->map->parsed_map[new_y][new_x] == WALL)
		return ;
	if (game->map->parsed_map[new_y][new_x] == COIN)
		game->map->coin--;
	if (game->map->parsed_map[new_y][new_x] == EXIT && game->map->coin <= 0)
		exit(0);
	if (game->map->parsed_map[new_y][new_x] == EXIT && game->map->coin != 0)
		return ;
	mlx_put_image_to_window(game->mlx, game->window, game->sprites[3],
		game->map->x * TILE, game->map->y * TILE);
	game->map->x = new_x;
	game->map->y = new_y;
	mlx_put_image_to_window(game->mlx, game->window, game->sprites[3],
		game->map->x * TILE, game->map->y * TILE);
	mlx_put_image_to_window(game->mlx, game->window, game->sprites[0],
		game->map->x * TILE, game->map->y * TILE);
	printf("Moves:	%d\n", ++game->moves);
}

int	key_checker(int key, t_game *game)
{
	// ft_printf("%i\n", key);
	if (key == ESC)
		destroy_window(game);
	if (key == UP || key == W)
		move(game, game->map->x, game->map->y - 1);
	if (key == DOWN || key == S)
		move(game, game->map->x, game->map->y + 1);
	if (key == LEFT || key == A)
		move(game, game->map->x - 1, game->map->y);
	if (key == RIGHT || key == D)
		move(game, game->map->x + 1, game->map->y);
	return (0);
}
