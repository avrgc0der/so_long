/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:21:52 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/09 17:21:26 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(int ac, char **av)
// {
// 	t_game	game;
// 	game.map = malloc(sizeof(t_parsemap));
// 	if (ac != 2)
// 		message("ERROR: Try ./so_long [map].ber", &game);
// }

void	init_vars(t_game *game)
{
	game->moves = 0;
	game->checks.coin = 0;
	game->checks.exit = 0;
	game->checks.coin_dup = -1;
	game->checks.exit_dup = -1;
}
