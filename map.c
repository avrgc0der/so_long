/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:57:05 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/20 15:46:53 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_size(t_game *game)
{
	int	i;
	int	temp;

	i = 0;
	game->map->columns = ft_strlen(game->map->prsd[0]);
	if (game->map->columns < 3 || game->map->rows < 3)
	{
		ft_putstr_fd("ERROR: Your map is too small.\n", 2);
		(free_maps(game->map->prsd, game->map->copy, game->map), exit(EF));
	}
	if (game->map->columns > 50 || game->map->rows > 23)
	{
		ft_putstr_fd("ERROR: Your map is too big.\n", 2);
		(free_maps(game->map->prsd, game->map->copy, game->map), exit(EF));
	}
	while (game->map->prsd[i])
	{
		temp = ft_strlen(game->map->prsd[i++]);
		if (temp != game->map->columns)
		{
			ft_putstr_fd("ERROR: Your map is not rectangular.\n", 2);
			(free_maps(game->map->prsd, game->map->copy, game->map), exit(EF));
		}
	}
}

void	linecount(char *path, t_parsemap *map)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(path, O_RDONLY);
	map->line = get_next_line(fd);
	if (!map->line || !map->line[0])
	{
		ft_putstr_fd("ERROR: You don't have a map.\n", 2);
		(free(map->line), (void)close(fd), free(map), exit(EF));
	}
	while (map->line)
	{
		i++;
		if (map->line[0] == '\n')
			map->emptyline = 1;
		if (map->line[0] != '\n' && map->emptyline == 1)
		{
			ft_putstr_fd("ERROR: Empty line found in map.\n", 2);
			(free(map->line), (void)close(fd), free(map), exit(EF));
		}
		else if (map->line != NULL)
			map->rows = i;
		free(map->line);
		map->line = get_next_line(fd);
	}
	free(map->line);
	close(fd);
}

void	map_borders(t_parsemap *map)
{
	int	i;

	i = 0;
	if (check_closed(map->prsd[0], WALL) == -1
		|| check_closed(map->prsd[map->rows - 1], WALL) == -1)
	{
		ft_putstr_fd("ERROR: Invalid border of the map.\n", 2);
		(free_maps(map->prsd, map->copy, map), exit(EF));
	}
	while (i < map->rows)
	{
		if (map->prsd[i][0] != WALL
			|| map->prsd[i][map->columns - 1] != WALL)
		{
			ft_putstr_fd("ERROR: Invalid border of the map.\n", 2);
			(free_maps(map->prsd, map->copy, map), exit(EF));
		}
		i++;
	}
}

void	check_tokens(t_parsemap *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->rows)
	{
		while (j < map->columns)
		{
			check_char(map, map->prsd[i][j]);
			if (map->prsd[i][j] == COIN)
				map->coin++;
			if (map->prsd[i][j] == EXIT)
				map->exit++;
			if (map->prsd[i][j] == PLAYER)
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
	int	i;
	int	fd;

	i = 0;
	linecount(path, map);
	fd = open(path, O_RDONLY); // protect fd EVERYWHERE
	map->prsd = malloc(sizeof(char *) * (map->rows + 1));
	map->copy = malloc(sizeof(char *) * (map->rows + 1));
	if (!map->prsd || !map->copy)
	{
		ft_putstr_fd("ERROR: Could not create the map.\n", 2);
		(free_maps(map->prsd, map->copy, map), exit(EF));
	}
	while (i < map->rows)
	{
		map->copy[i] = get_next_line(fd);
		map->prsd[i] = ft_strtrim(map->copy[i], "\n");
		free(map->copy[i]);
		map->copy[i] = ft_strdup(map->prsd[i]);
		i++;
	}
	map->prsd[i] = NULL;
	map->copy[i] = NULL;
	close(fd);
}
