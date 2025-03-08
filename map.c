/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:57:05 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/08 16:49:25 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_map(t_game *game)
{
	int	row;

	row = 0;
	while (game->map.parsed_map[row])
	{
		free(game->map.parsed_map[row]);
		row++;
	}
}

void	check_size(t_game *game)
{
	int	i;
	int	temp;

	i = 0;
	game->map.map_width = ft_strlen(game->map.parsed_map[0]);
	if (game->map.map_height < 3 || game->map.map_width < 3)
	{
		message("ERROR: Your map is too small.", game);
		(free_maps(game->map.parsed_map, game->map.copy_map, &game->map), exit(EXIT_FAILURE));
	}
	if (game->map.map_height > 23 || game->map.map_width > 11)
	{
		message("ERROR: Your map is too big.", game);
		(free_maps(game->map.parsed_map, game->map.copy_map, &game->map), exit(EXIT_FAILURE));
	}
	while (game->map.parsed_map[i])
	{
		temp = ft_strlen(game->map.parsed_map[i++]);
		if (temp != game->map.map_width)
		{
			message("ERROR: Your map is not rectangular.", game);
			(free_maps(game->map.parsed_map, game->map.copy_map, &game->map), exit(EXIT_FAILURE));
		}
	}
}
