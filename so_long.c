/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:36:09 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/06 15:58:05 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	moves(int keycode, t_mlx *game)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (y < game->height)
// 	{
// 		while (x < game-> width && game->map[y][x] != 'P')
// 			x++;
// 		x = 0;
// 		y++;
// 	}
// 	ft_moves(keycode, game);
// }

int	ft_close(void)
{
	exit (0);
}

int main(int ac, char **av)
{
	t_mlx		game;
	int			fd;

	(void)av;
	if (ac != 2)
		return (0);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	fd = open("maps/map1.ber", O_RDONLY);
	if (fd == -1)
		return (1);
	game.map = get_map(fd);
	game.height = get_height(game.map);
	game.width = ft_length(game.map[0]);
	// the_parse(&game);
	if (((game.width * SPRITE_SIZE) > MAX_WIDTH) || (game.height * SPRITE_SIZE) > MAX_HEIGHT)
		return (1);
	game.c_count = get_count(&game);
	game.moves = 0;
	put_sprite(&game, SPRITE_SIZE);
	ft_render(&game);
	mlx_hook(game.window, 17, 0, ft_close, &game);
	mlx_key_hook(game.window, ft_move, &game);
	mlx_loop(game.mlx);
	return (0);
}
