/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:51:42 by enoshahi          #+#    #+#             */
/*   Updated: 2025/02/24 15:22:54 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	free_me(game);
	exit(1);
}
