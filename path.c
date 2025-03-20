/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:28:34 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/20 15:39:23 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pathfinder(char **copy, int x, int y, t_parsemap *map)
{
	if (map->coin_dup == -1)
		map->coin_dup = map->coin;
	if (x == map->x_exit && y == map->y_exit)
		map->exit_dup = 0;
	if (x < 0 || x > map->columns || y < 0
		|| y > map->rows || copy[y][x] == WALL)
		return ;
	if (copy[y][x] == COIN)
		map->coin_dup--;
	copy[y][x] = WALL;
	pathfinder(copy, x + 1, y, map);
	pathfinder(copy, x - 1, y, map);
	pathfinder(copy, x, y + 1, map);
	pathfinder(copy, x, y - 1, map);
}
