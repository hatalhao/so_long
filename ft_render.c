/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:36:51 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/06 17:05:52 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_sprite(t_mlx *game, int sprite_size)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/deep_ocean_battlemap_1_.xpm", &sprite_size, &sprite_size); // size 60
	game->zero = mlx_xpm_file_to_image(game->mlx, "textures/Ground_03.xpm", &sprite_size, &sprite_size); // size 60
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/popeyedilmo.xpm", &sprite_size, &sprite_size); // size 30
	game->collectible = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &sprite_size, &sprite_size); // size 30
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/Door4.xpm", &sprite_size, &sprite_size); // size 30
	game->window = mlx_new_window(game->mlx, game->width * SPRITE_SIZE, game->height * SPRITE_SIZE, "so_long");
	if (!game->window || !game->wall || !game->zero || !game->collectible || !game->exit || !game->player)
		exit(1);
}

void	ft_render(t_mlx *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while(x < game->width)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall, x * SPRITE_SIZE, y * SPRITE_SIZE);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->window, game->zero, x * SPRITE_SIZE, y * SPRITE_SIZE);
			else if (game->map[y][x] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->window, game->player, x * SPRITE_SIZE, y * SPRITE_SIZE);
				game->p_x = x;
				game->p_y = y;
			}
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->collectible, x * SPRITE_SIZE, y * SPRITE_SIZE);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit, x * SPRITE_SIZE, y * SPRITE_SIZE);
			else
			{
				// mlx_destroy_window(game->mlx, game->window);
				// free (game->mlx);
				perror("Invalid Symbol in The Map");
				system("leaks so_long");
				exit(1);
			}
			x++;
		}
		y++;
	}
}
