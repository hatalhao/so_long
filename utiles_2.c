/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:56:49 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/10 18:30:40 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str, t_mlx *game)
{
	if (game)
		free_alloc(game);
	str_fd(str, 2);
	exit(1);
}

void	ff_verdict(t_mlx *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map_dup[y][x] != '1' && game->map_dup[y][x] != '2'
				&& (game->map_dup[y][x] == 'E' || game->map_dup[y][x] == 'C'))
			{
				ft_error("Map Not Filled Well\n", game);
				exit(1);
			}
			x++;
		}
		y++;
	}
}

void	ft_flood_fill(char **map, int y, int x)
{
	if (map[y][x] == 'E')
		map[y][x] = '1';
	if (map[y][x] == '1' || map[y][x] == '2')
		return ;
	map[y][x] = '2';
	ft_flood_fill(map, y, x + 1);
	ft_flood_fill(map, y, x - 1);
	ft_flood_fill(map, y + 1, x);
	ft_flood_fill(map, y - 1, x);
}

char	**map_dup(t_mlx *game)
{
	int		y;
	char	**map_dup;

	if (!(game->map) || !*(game->map))
		return (NULL);
	map_dup = (char **)malloc((game->height + 1) * sizeof(char *));
	if (!map_dup)
		return (NULL);
	y = 0;
	while (y < game->height)
	{
		map_dup[y] = ft_duplicate(game->map[y]);
		y++;
	}
	map_dup[y] = NULL;
	return (map_dup);
}
