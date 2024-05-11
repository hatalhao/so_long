/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:36:51 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/11 20:55:57 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_mlx *game)
{
	game->moves++;
	ft_printf("%d\n", game->moves);
}

void	put_sprite(t_mlx *game, int sprite_size)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&sprite_size, &sprite_size);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&sprite_size, &sprite_size);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/ww.xpm",
			&sprite_size, &sprite_size);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "textures/meth.xpm",
			&sprite_size, &sprite_size);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&sprite_size, &sprite_size);
	game->window = mlx_new_window(game->mlx, game->width * SPRITE_SIZE,
			game->height * SPRITE_SIZE, "so_long");
	if (!game->window || !game->wall || !game->floor || !game->collectible
		|| !game->exit || !game->player)
	{
		str_fd("Error:Invalid Image(s)\n", 2);
		exit(1);
	}
}

void	fill_map(t_mlx *game, int y, int x)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->floor, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	else if (game->map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->player, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
		game->p_x = x;
		game->p_y = y;
	}
	else if (game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->floor, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
		mlx_put_image_to_window(game->mlx, game->window, game->collectible, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	}
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit, x
			* SPRITE_SIZE, y * SPRITE_SIZE);
	else
		ft_error("Error: Invalid Symbol in The Map\n", game);
}

void	ft_render(t_mlx *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			fill_map(game, y, x);
			x++;
		}
		y++;
	}
}
