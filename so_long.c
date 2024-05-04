/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:36:09 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/04 20:12:01 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(int keycode, t_mlx *game)
{
	if (keycode == 123 || keycode == 0)
		move_left(game);
	else if (keycode == 124 || keycode == 2)
		move_right(game);
	else if (keycode == 125 || keycode == 1)
		move_down(game);
	else if (keycode == 126 || keycode == 13)
		move_up(game);
}

int	ft_close(int keycode, t_mlx *game)
{
	if (keycode == 53)
	{
		mlx_destroy_image(game->mlx, game->img);
		mlx_destroy_image(game->mlx, game->exit);
		mlx_destroy_image(game->mlx, game->img_z);
		mlx_destroy_image(game->mlx, game->player);
		mlx_destroy_image(game->mlx, game->collectible);
		mlx_destroy_window(game->mlx, game->window);
		exit (0);
	}
	else
		return (1);
}

int	ft_close2(t_mlx *game)
{
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->img_z);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->collectible);
	mlx_destroy_window(game->mlx, game->window);
	exit (0);
}

int main(int ac, char **av)
{
	t_mlx		game;
	// t_window	window;
	int			fd;
	int			sprite_size;

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
	game.window = mlx_new_window(game.mlx, game.width * 32, game.height * 32, *av + 2);
	game.img = mlx_xpm_file_to_image(game.mlx, "textures/deep_ocean_battlemap_1_.xpm", &sprite_size, &sprite_size);
	game.img_z = mlx_xpm_file_to_image(game.mlx, "textures/Ground_03.xpm", &sprite_size, &sprite_size);
	game.player = mlx_xpm_file_to_image(game.mlx, "textures/popeyedilmo.xpm", &sprite_size, &sprite_size);
	game.collectible = mlx_xpm_file_to_image(game.mlx, "textures/collectible.xpm", &sprite_size, &sprite_size);
	game.exit = mlx_xpm_file_to_image(game.mlx, "textures/Door4.xpm", &sprite_size, &sprite_size);
	printf("*************************\n");
	int	x = 0;
	int	y = 0;
	while(y < game.height)
	{
		while(x < game.width)
		{
			if (game.map[y][x] == '1')
				mlx_put_image_to_window(game.mlx, game.window, game.img, x * 32, y * 32);
			else if (game.map[y][x] == '0')
				mlx_put_image_to_window(game.mlx, game.window, game.img_z, x * 32, y * 32);
			else if (game.map[y][x] == 'P')
				mlx_put_image_to_window(game.mlx, game.window, game.player, x * 32, y * 32);
			else if (game.map[y][x] == 'C')
				mlx_put_image_to_window(game.mlx, game.window, game.collectible, x * 32, y * 32);
			else if (game.map[y][x] == 'E')
				mlx_put_image_to_window(game.mlx, game.window, game.exit, x * 32, y * 32);
			else
			{
				// free everything allocated;
				mlx_destroy_window(game.mlx, game.window);
				free (game.mlx);
				perror("Invalid Symbol in The Map");
				exit(1);
			}	
			x++;
		}
		y++;
		x = 0;
	}
	mlx_hook(game.window, 17, 0, ft_close2, &game);
	mlx_key_hook(game.window, ft_close, &game);
	// mlx_hook(game.window, 1);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.window);
	mlx_destroy_image(game.mlx, game.img);
	free(game.mlx);
	return (0);
}
