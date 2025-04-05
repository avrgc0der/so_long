/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:03:31 by enoshahi          #+#    #+#             */
/*   Updated: 2025/04/05 18:35:13 by tabadawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	i = 0;
	while (i < 5)
	{
		fd = open(list[i], O_RDONLY);
		if (fd == -1)
		{
			write(1, "Could not find image.", 21);
			exit(EF);
		}
		close(fd);
		i++;
	}
}
