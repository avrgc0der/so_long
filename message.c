/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:54:15 by enoshahi          #+#    #+#             */
/*   Updated: 2025/02/24 14:03:16 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	message(char *msg, t_game *game)
{
	ft_printf("%s", msg);
	destroy_window(game);
	exit(0);
}
