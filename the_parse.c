/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:48:48 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/06 18:32:09 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		all_syms(t_mlx *game)
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
				return (0);
		}
		h++;
	}
	return (1);
}

int		is_rectangular(t_mlx *game)
{
	int len;
	int h;

	h = 0;
	len = ft_length(game->map[h++]);
	if (h < 2)
		return (0);
	while (h < game->height)
	{
		if (len != (int)ft_length(game->map[h]))
			return (0);
		h++;
	}
	return (1);
}

int		wall_encircled(t_mlx *game)
{
	int	w;
	int	h;

	h = 0;
	w = 0;
	while (w < game->width)
	{
		if (game->map[h][w] != '1' || game->map[game->height -1][w] == '1')
			return (0);
		w++;
	}
	w = 0;
	while (h < game->height)
	{
		if (game->map[h][w] != '1' || game->map[h][game->width - 1] != '1')
			return (0);
		h++;
	}
	return (1);
}
void	the_parse(t_mlx *game, char *av)
{
	int	i;

	i = 0;
	if (ft_length(av) < 5)
	{
		ft_putstr_fd("Error map name\n", 2);
		exit (1);
	}
	while (i < game->height)
	{
		if (!all_syms(game) || !is_rectangular(game) || !wall_encircled(game))
			exit (1);
		i++;
	}		
	exit (0);
}
