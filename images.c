/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:03:31 by enoshahi          #+#    #+#             */
/*   Updated: 2025/03/16 03:12:37 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// * Static: The array persists in memory after the function ends,
// * ensuring the list remains valid for later use.

void	imglist(void)
{
	static char	*list[5] = {
		"textures/sprite.xpm",
		"textures/wall.xpm",
		"textures/floor.xpm",
		"textures/collectible.xpm",
		"textures/exit.xpm",
	};
	int			i;
	int			fd;

	while (i < 5)
	{
		fd = open(list[i], O_RDONLY);
		if (fd == -1)
			(write(1, "Could not find file.", 21), exit(EF));
		close(fd);
		i++;
	}
}
