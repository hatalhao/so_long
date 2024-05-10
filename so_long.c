/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:36:09 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/11 00:55:43 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_name(char *av)
{
	if (ft_strcmp(".ber", ft_strrchr(av, '.')))
		ft_error("Error: Invalid Map Name\n", NULL);
	return ;
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;	
	}
	free(map);
}

void	assignments(t_mlx *game, char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		str_fd("Error: Invalid File\n", 2);
		exit(1);
	}
	map_name(av);
	game->map = get_map(fd);
	game->height = get_height(game->map);
	if (game->height > MAX_VALUE)
	{
		free_map(game->map);
		ft_error("The Map is Too Big\n", NULL);
	}
	game->width = ft_length(*(game->map));
	if (game->width > MAX_VALUE)
	{
		free_map(game->map);
		ft_error("The Map is Too Big\n", NULL);
	}	
	game->map_dup = map_dup(game);
	get_count(game);
	player_coords(game);
}

int	ft_close(void)
{
	system("leaks so_long");
	exit(0);
}

int	main(int ac, char **av)
{
	t_mlx	game;

	if (ac != 2)
		return (0);
	assignments(&game, *(av + 1));
	game.moves = 0;
	the_parse(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	put_sprite(&game, SPRITE_SIZE);
	ft_render(&game);
	mlx_hook(game.window, 17, 0, ft_close, &game);
	mlx_key_hook(game.window, ft_move, &game);
	mlx_loop(game.mlx);
	free_map(game.map);
	free_map(game.map_dup);
	return (0);
}
