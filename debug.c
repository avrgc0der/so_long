/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:40:17 by enoshahi          #+#    #+#             */
/*   Updated: 2025/02/28 18:59:12 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	print_data(t_game *game);

int main(void)
{
	t_game *game;
	game = malloc(sizeof(t_game));

	game->map_height = 1920;
	game->map_width = 1080;
	game->player.x = 48;
	game->player.y = 0;
	game->checks.coin = 1;
	game->checks.exit = 1;
	
	message("hewwo", game);

	printf("======================================\n\n");
	printf("\033[1m\033[31m""map height:\033[0m	%d\n", game->map_height);
	printf("map width:	%d\n", game->map_width);
	printf("player x:	%d\nplayer y:	%d\n", game->player.x, game->player.y);
	printf("coins:		%d\n", game->checks.coin);
	printf("exit:		%d\n", game->checks.exit);
	printf("\n======================================\n");
}

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	printf("======================================\n\n");
	while (i < game->map_height)
	{
		printf("%s\n", game->parsed_map[i]);
		i++;
	}
	printf("\n======================================\n");
}

void	print_dup(t_game *game)
{	
	int	i;

	i = 0;
	printf("======================================\n\n");
	while (i < game->map_height)
	{
		printf("%s\n", game->copy_map[i]);
		i++;
	}
	printf("\n======================================\n");
}
