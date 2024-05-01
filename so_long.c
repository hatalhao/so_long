/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:36:09 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/01 07:10:46 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int main(int ac, char **av)
{
	t_mlx	game;
	char	*line;
	int		fd;

	if (ac < 2)
		return (0);
	fd = open("map/map.ber", O_RDONLY);
	line = get_next_line(fd);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 1920, 1080, "so_long");
	game.height = get_height(fd);
	game.width = ft_strlen(line);
	game.map = get_map(fd);
	mlx_loop(game.mlx);
	
	// mlx_hook(game.mlx, );
	free(line);
	return (0);
}
