/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:21:52 by enoshahi          #+#    #+#             */
/*   Updated: 2025/02/28 18:58:17 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(int ac, char **av)
// {
// 	t_game	vars;

// 	if (ac <= 1)
// 	{
// 		message("Ewwow!!!!! uh ohhh ..... :3", vars);
// 		exit(1);
// 	}
// }

void	init_vars(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->parsed_map = NULL;
	game->player.movement = 0;
	game->checks.coin = 0;
	game->checks.exit = 0;
	game->checks.coin_dup = 0;
	game->checks.exit_dup = 0;
	// game->
	
}
