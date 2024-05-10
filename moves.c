/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:01:08 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/10 19:03:41 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_mlx *game)
{
	if (game->map[game->p_y][game->p_x - 1] == '1')
		return ;
	else if (game->map[game->p_y][game->p_x - 1] == 'E')
	{
		if (game->c_count == 0)
		{
			print_moves(game);
			exit(0);
		}
		else
			return ;
	}
	else if (game->map[game->p_y][game->p_x - 1] == 'C')
		game->c_count--;
	game->map[game->p_y][game->p_x] = '0';
	game->map[game->p_y][game->p_x - 1] = 'P';
	// print_moves(game);
	mlx_clear_window(game->mlx, game->window);
	ft_render(game);
}

void	move_right(t_mlx *game)
{
	if (game->map[game->p_y][game->p_x + 1] == '1')
		return ;
	else if (game->map[game->p_y][game->p_x + 1] == 'E')
	{
		if (game->c_count == 0)
		{
			print_moves(game);
			exit(0);
		}
		else
			return ;
	}
	else if (game->map[game->p_y][game->p_x + 1] == 'C')
		game->c_count--;
	game->map[game->p_y][game->p_x] = '0';
	game->map[game->p_y][game->p_x + 1] = 'P';
	print_moves(game);
	mlx_clear_window(game->mlx, game->window);
	ft_render(game);
}

void	move_down(t_mlx *game)
{
	if (game->map[game->p_y + 1][game->p_x] == '1')
		return ;
	else if (game->map[game->p_y + 1][game->p_x] == 'E')
	{
		if (game->c_count == 0)
		{
			print_moves(game);
			exit(0);
		}
		else
			return ;
	}
	else if (game->map[game->p_y + 1][game->p_x] == 'C')
		game->c_count--;
	game->map[game->p_y][game->p_x] = '0';
	game->map[game->p_y + 1][game->p_x] = 'P';
	print_moves(game);
	mlx_clear_window(game->mlx, game->window);
	ft_render(game);
}

void	move_up(t_mlx *game)
{
	if (game->map[game->p_y - 1][game->p_x] == '1')
		return ;
	else if (game->map[game->p_y - 1][game->p_x] == 'E')
	{
		if (game->c_count == 0)
		{
			print_moves(game);
			exit(0);
		}
		else
			return ;
	}
	else if (game->map[game->p_y - 1][game->p_x] == 'C')
		game->c_count--;
	game->map[game->p_y][game->p_x] = '0';
	game->map[game->p_y - 1][game->p_x] = 'P';
	print_moves(game);
	mlx_clear_window(game->mlx, game->window);
	ft_render(game);
}

int	ft_move(int keycode, t_mlx *game)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 123 || keycode == 0)
		move_left(game);
	else if (keycode == 124 || keycode == 2)
		move_right(game);
	else if (keycode == 125 || keycode == 1)
		move_down(game);
	else if (keycode == 126 || keycode == 13)
		move_up(game);
	return (0);
}
