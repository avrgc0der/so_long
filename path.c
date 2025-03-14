/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:28:34 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/14 04:43:55 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pathfinder(char **copy, int x, int y, t_parsemap *map)
{
	if (map->coin_dup == -1 && map->exit_dup == -1)
	{
		map->coin_dup = map->coin;
		map->exit_dup = map->exit;
	}
	if (x < 0 || x > map->columns || y < 0
		|| y > map->rows || copy[x][y] == WALL)
		return ;
	if (copy[x][y] == COIN)
		map->coin_dup--;
	if (copy[x][y] == EXIT)
	{
		map->exit_dup--;
		map->x_exit = map->x;
		map->y_exit = map->y;
	}
	copy[x][y] = WALL;
	pathfinder(copy, x + 1, y, map);
	pathfinder(copy, x - 1, y, map);
	pathfinder(copy, x, y + 1, map);
	pathfinder(copy, x, y - 1, map);
}
