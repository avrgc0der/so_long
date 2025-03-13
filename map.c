/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:57:05 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/14 03:11:52 by enoshahi         ###   ########.fr       */
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
		ft_putstr_fd("ERROR: Your map is too small.\n", 2);
		(free_maps(game->map.parsed_map, game->map.copy_map, &game->map), exit(EF));
	}
	if (game->map.map_height > 23 || game->map.map_width > 11)
	{
		ft_putstr_fd("ERROR: Your map is too big.\n", 2);
		(free_maps(game->map.parsed_map, game->map.copy_map, &game->map), exit(EF));
	}
	while (game->map.parsed_map[i])
	{
		temp = ft_strlen(game->map.parsed_map[i++]);
		if (temp != game->map.map_width)
		{
			ft_putstr_fd("ERROR: Your map is not rectangular.\n", 2);
			(free_maps(game->map.parsed_map, game->map.copy_map, &game->map), exit(EF));
		}
	}
}

void linecount(char *path, t_parsemap *map)
{
	int fd;
	int i;

	i = 0;
	fd = open(path, O_RDONLY);
	map->line = get_next_line(fd);
	if(!map->line)
	{
		i++;
		if (map->line[0] == '\n')
		map->emptyline = 1;
		if (map->line[0] != '\n' && map->emptyline == 1)
		{
			ft_putstr_fd("ERROR: Empty line found in map.\n", 2);
			(free(map->line), (void)close(fd), free(map), exit(EF));
		}
		else if (map->line != '\n')
			map->map_width = i;
		free(map->line);
		map->line = get_next_line(fd);
	}
	free(map->line);
	close(fd);
}

void map_borders(t_parsemap *map)
{
	int i;

	i = 0;
	
}