/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:13:41 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/20 15:23:59 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_path(char *path, t_parsemap *map)
{
	int	fd;

	if (!path)
		(ft_putstr_fd("ERROR: No such path.\nTry ./so_long [Map].ber\n", 2),
			free(map), exit(EF));
	if (ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 4) != 0)
		(ft_putstr_fd("ERROR: Wrong extension.\nTry ./so_long [Map].ber\n", 2),
			free(map), exit(EF));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		(ft_putstr_fd("ERROR: No file exists.\n", 2), free(map), exit(EF));
	close(fd);
}

int	check_closed(char *row, char c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(row);
	while (i < len)
	{
		if (row[i] != c)
			return (-1);
		i++;
	}
	return (1);
}

void	check_char(t_parsemap *map, char c)
{
	if (c != PLAYER && c != COIN && c != WALL && c != FLOOR && c != EXIT)
	{
		ft_putstr_fd("ERROR: Invalid token in the map.\n", 2);
		(free_maps(map->prsd, map->copy, map), exit(EF));
	}
}

void	init_map(t_game *game)
{
	game->map->player = 0;
	game->map->coin = 0;
	game->map->exit = 0;
	game->map->x = 0;
	game->map->y = 0;
	game->map->coin_dup = -1;
	game->map->exit_dup = 1;
	game->map->emptyline = -1;
	game->map->rows = 0;
	game->map->columns = 0;
	game->map->copy = NULL;
	game->map->prsd = NULL;
}
