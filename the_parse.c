/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:48:48 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/10 18:24:20 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_name(char *av)
{
	if (ft_strcmp(".ber", ft_strrchr(av, '.')))
		ft_error("Error: Invalid Map Name\n", NULL);
	return (1);
}

int	all_syms(t_mlx *game)
{
	int	w;
	int	h;

	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (w < game->width)
		{
			if (game->map[h][w] == 'P' || game->map[h][w] == '1'
				|| game->map[h][w] == 'C' || game->map[h][w] == 'E'
				|| game->map[h][w] == '0')
				w++;
			else
			{
				ft_error("Foreigner Symbol\n", game);
				return (0);
			}
		}
		h++;
	}
	return (1);
}

int	is_rectangular(t_mlx *game)
{
	int	len;
	int	h;

	h = 0;
	len = ft_length(game->map[h++]);
	while (h < game->height)
	{
		if (len != (int)ft_length(game->map[h]))
		{
			printf("Rect\n");
			return (0);
		}
		h++;
	}
	if (h < 2)
	{
		printf("SMALL MAP\n");
		return (0);
	}
	return (1);
}

int	wall_encircled(t_mlx *game)
{
	int	w;
	int	h;

	h = 0;
	w = 0;
	while (w < game->width)
	{
		if (game->map[h][w] != '1' || game->map[game->height - 1][w] != '1')
		{
			printf("NOT CIRCLED 1\n");
			return (0);
		}
		w++;
	}
	w = 0;
	while (h < game->height)
	{
		if (game->map[h][w] != '1' || game->map[h][game->width - 1] != '1')
		{
			printf("NOT CIRCLED 2\n");
			return (0);
		}
		h++;
	}
	return (1);
}

void	the_parse(t_mlx *game, char *av)
{
	if (!all_syms(game) || !is_rectangular(game) || !wall_encircled(game)
		|| !map_name(av))
	{
		printf("%s --> HERE\n", __FUNCTION__);
		exit(1);
	}
	ft_flood_fill(game->map_dup, game->p_y, game->p_x);
	ff_verdict(game);
}
