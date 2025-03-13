/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:15:21 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/12 15:51:11 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_checker(int key, t_game *game)
{
	if (key == ESC)
		destroy_window(game);
	if (key == UP)
		up(game);
	if (key == DOWN)
		down(game);
	if (key == LEFT)
		left(game);
	if (key == RIGHT)
		right(game);
	return (0);
}
