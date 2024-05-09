/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:36:09 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/09 16:24:51 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_alloc(t_mlx *game)
{
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->zero);
	mlx_destroy_image(game->mlx, game->collectible);
	mlx_destroy_window(game->mlx, game->window);
	free(game->map);
	free(game->map_dup);
}

void	assignments(t_mlx *game, char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error : Invalid File Descriptor\n", 2);
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
	assignments(&game, av[1]);
	the_parse(&game, *(av + 1));
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	put_sprite(&game, SPRITE_SIZE);
	ft_render(&game);
	mlx_hook(game.window, 17, 0, ft_close, &game);
	mlx_key_hook(game.window, ft_move, &game);
	mlx_loop(game.mlx);
	system("leaks so_long");
	free_alloc(&game);
	return (0);
}
