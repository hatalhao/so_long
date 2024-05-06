/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:48:48 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/06 17:16:18 by hatalhao         ###   ########.fr       */
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
	while ()	
		len = ft_length(game->map[0]);
}

int		wall_encircled(t_mlx *game)
{
	
}
void	the_parse(t_mlx *game, char *av)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (!is_rectangular(game) || !wall_encircled(game) || !all_syms(game))
		i++;
	}		
	exit (1);
}
