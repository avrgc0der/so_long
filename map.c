/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:57:05 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/14 04:32:47 by enoshahi         ###   ########.fr       */
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
	game->map.columns = ft_strlen(game->map.parsed_map[0]);
	if (game->map.columns < 3 || game->map.rows < 3)
	{
		ft_putstr_fd("ERROR: Your map is too small.\n", 2);
		(free_maps(game->map.parsed_map, game->map.copy_map, &game->map), exit(EF));
	}
	if (game->map.columns > 23 || game->map.rows > 11)
	{
		ft_putstr_fd("ERROR: Your map is too big.\n", 2);
		(free_maps(game->map.parsed_map, game->map.copy_map, &game->map), exit(EF));
	}
	while (game->map.parsed_map[i])
	{
		temp = ft_strlen(game->map.parsed_map[i++]);
		if (temp != game->map.columns)
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
			map->rows = i;
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
	if (check_closed(map->parsed_map[0], WALL) == -1
		|| check_closed(map->parsed_map[map->rows - 1], WALL) == 0)
	{
		ft_putstr_fd("ERROR: Invalid border of the map.\n", 2);
		(free_maps(map->parsed_map, map->copy_map, map), exit(EF));
	}
	while (i < map->rows)
	{
		if (map->parsed_map[i][0] != WALL
			|| map->parsed_map[i][map->columns - 1] != WALL)
		{
			ft_putstr_fd("ERROR: Invalid border of the map.\n", 2);
			(free_maps(map->parsed_map, map->copy_map, map), exit(EF));
		}
		i++;
	}
}

void	check_tokens(t_parsemap *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->rows)
	{
		while (j < map->columns)
		{
			check_char(map->parsed_map[i][j], map);
			if (map->parsed_map[i][j] == COIN)
				map->coin++;
			if (map->parsed_map[i][j] == EXIT)
				map->exit++;
			if (map->parsed_map[i][j] == PLAYER)
			{	
				map->player++;
				map->x = j;
				map->y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	get_map(char *path, t_parsemap *map)
{
	int i;
	int fd;

	i = 0;
	fd = (path, O_RDONLY);
	linecount(path, map);
	map->parsed_map = malloc(sizeof(char) * (map->rows + 1));
	map->copy_map = malloc(sizeof(char) * (map->rows + 1));
	if (!map->parsed_map || !map->copy_map)
	{
		ft_putstr_fd("ERROR: Could not create the map.\n", 2);
		(free_maps(map->parsed_map, map->copy_map, map), exit(EF));
	}
	while (i < map->rows)
	{
		map->parsed_map[i] = ft_strtrim(get_next_line(fd), "\n");
		map->copy_map[i] = ft_strdup(map->parsed_map[i]);
		i++;
	}
	map->parsed_map[i] = NULL;
	map->copy_map[i] = NULL;
	close(fd);
}