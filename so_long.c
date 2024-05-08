/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:36:09 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/08 06:34:03 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assignments(t_mlx *game)
{
	int	fd;

	fd = open("maps/map1.ber", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Invalid File Descriptor\n", 2);
		exit(1);	
	}
	game->map = get_map(fd);
	game->height = get_height(game->map);
	game->width = ft_length(*(game->map));
	game->c_count = get_count(game);
	game->map_dup = map_dup(game);
	game->moves = 0;
	player_coords(game);
}

int	ft_close(void)
{
	exit (0);
}

int main(int ac, char **av)
{
	t_mlx		game;

	if (ac != 2)
		return (0);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	assignments(&game);
	the_parse(&game, *av + 1);
	if (((game.width * SPRITE_SIZE) > MAX_WIDTH) || (game.height * SPRITE_SIZE) > MAX_HEIGHT)
		return (1);
	put_sprite(&game, SPRITE_SIZE);
	ft_render(&game);
	mlx_hook(game.window, 17, 0, ft_close, &game);
	mlx_key_hook(game.window, ft_move, &game);
	mlx_loop(game.mlx);
	return (0);
}
