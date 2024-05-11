/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:47:22 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/11 20:33:27 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify_count(t_mlx *game)
{
	if (game->c_count < 1 || game->e_count != 1 || game->p_count != 1)
	{
		free_map(game->map);
		free_map(game->map_dup);
		str_fd("Error: Missing/Extra Symbols \n", 2);
		exit(1);
	}
	else
		return ;
}

void	player_coords(t_mlx *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->p_y = y;
				game->p_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	get_count(t_mlx *game)
{
	int	x;
	int	y;

	y = 0;
	game->c_count = 0;
	game->e_count = 0;
	game->p_count = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C')
				game->c_count++;
			else if (game->map[y][x] == 'E')
				game->e_count++;
			else if (game->map[y][x] == 'P')
				game->p_count++;
			x++;
		}
		y++;
	}
	verify_count(game);
}

int	get_height(char **map)
{
	int	h;

	if (!map || !*map)
		return (0);
	h = 0;
	while (map[h])
		h++;
	return (h);
}

char	**get_map(int fd)
{
	char	*line;
	char	*total;
	char	**map;

	total = NULL;
	line = get_next_line(fd);
	while (1)
	{
		total = ft_join(total, line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	if (!total)
	{
		str_fd("Error: The Map is empty\n", 2);
		exit(1);
	}
	long_parse(total);
	map = ft_split(total, '\n');
	free(total);
	return (map);
}
