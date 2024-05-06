/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:36:09 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/06 03:54:04 by hatalhao         ###   ########.fr       */
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

int	ft_close2(t_mlx *game)
{
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->zero);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->collectible);
	mlx_destroy_window(game->mlx, game->window);
	exit (0);
}

int main(int ac, char **av)
{
	t_mlx		game;
	int			fd;
	int			sprite_size;

	(void)av;
	if (ac < 2 || ac > 2)
		return (0);
	sprite_size = 0;
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	fd = open("maps/map1.ber", O_RDONLY);
	game.map = get_map(fd);
	game.height = get_height(game.map);
	game.width = ft_length(game.map[0]);
	if (((game.width * sprite_size) > max_width) || (game.height * sprite_size) > max_height)
		return (1);
	game.c_count = get_count(&game);
	game.moves = 0;
	put_sprite(&game, sprite_size);
	ft_render(&game);
	printf("*************************\n");
	// mlx_key_hook(game.window, ft_close, &game);
	mlx_hook(game.window, 17, 0, ft_close2, &game);
	mlx_key_hook(game.window, ft_move, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.window);
	mlx_destroy_image(game.mlx, game.wall);
	free(game.mlx);
	return (0);
}
