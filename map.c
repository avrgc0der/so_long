/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:57:05 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/02 14:44:36 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->parsed_map[i])
	{
		free(game->parsed_map[i]);
		i++;
	}
}
