/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:47:22 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/09 23:57:55 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_coords(t_mlx *game)
{
	int	y;
	int x;

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

int		get_count(t_mlx *game)
{
	int	counter;
	int	x;
	int	y;

	y = 0;
	counter = 0;
	while (y < game->height)
	{
		x = 0;	
		while(x < game->width)
		{
			if (game->map[y][x] == 'C')
				counter++;
			x++;
		}
		y++;
	}
	return (counter);
}

int		get_height(char	**map)
{
	int		h;

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
		printf("--> [%s]\n", line);
		line = get_next_line(fd);
		// if (*line == '\n')
		// {
		// 	ft_putstr_fd("Only newline\n", 2);
		// 	ft_free (&total);
		// 	exit(1);
		// }
		if (!line)
			break ;
	}
	long_parse(total);
	map = ft_split(total, '\n');
	free (total);
	return (map);
}
