/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:46:52 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/20 14:25:58 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moves_on_screen(t_game *game)
{
	char	*str;

	mlx_put_image_to_window(game->mlx, game->window,
		game->sprites[4], 2 * TILE, 0 * TILE);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprites[4], 1 * TILE, 0 * TILE);
	mlx_string_put(game->mlx, game->window, 65, 25, 0xffffff, "<moves> =");
	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->window, 160, 25, 0xffffff, str);
	free(str);
	return (0);
}

void	init_tiles(t_game *game)
{
	game->map->tile = TILE;
	game->sprites[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/sprite.xpm", &game->map->tile, &game->map->tile);
	game->sprites[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &game->map->tile, &game->map->tile);
	game->sprites[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &game->map->tile, &game->map->tile);
	game->sprites[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &game->map->tile, &game->map->tile);
	game->sprites[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &game->map->tile, &game->map->tile);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	init_tiles(game);
	render_edges(game);
	while (++i < game->map->rows - 1)
	{
		while (++j < game->map->columns - 1)
		{
			if (game->map->prsd[i][j] == WALL)
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites[4], j * TILE, i * TILE);
			if (game->map->prsd[i][j] != WALL)
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites[3], j * TILE, i * TILE);
		}
		j = 0;
	}
	render_elements(game);
	moves_on_screen(game);
}

void	render_edges(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map->prsd[i])
	{
		while (game->map->prsd[i][j])
		{
			if ((i == 0 || i == game->map->rows - 1)
				|| (j == 0 || j == game->map->columns - 1))
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites[4], j * TILE, i * TILE);
			j++;
		}
		j = 0;
		i++;
	}
}

void	render_elements(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (game->map->prsd[++i])
	{
		while (game->map->prsd[i][++j])
		{
			if (game->map->prsd[i][j] == COIN)
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites[1], j * TILE, i * TILE);
			else if (game->map->prsd[i][j] == PLAYER)
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites[0], j * TILE, i * TILE);
			else if (game->map->prsd[i][j] == EXIT)
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprites[2], j * TILE, i * TILE);
		}
		j = -1;
	}
}
