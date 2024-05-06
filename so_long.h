/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:20:33 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/06 03:47:06 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <math.h>
# include <mlx.h>
# include "libft/libft.h"

typedef struct	s_mlx
{
	void	*mlx;
	void	*window;
	void	*wall;
	void	*zero;
	char	**map;
	char	*addr;
	int		height;
	int		width;
	void	*player;
	void	*exit;
	void	*collectible;
	int		c_count;
	int		p_x;
	int		p_y;
	int		moves;
}				t_mlx;
// #ifndef
# define max_width	2560
# define max_height 1440

// typedef	struct	s_window
// {
// 	int			height;
// 	int			width;
// }				t_window;

/*	so_long functions	*/

int		get_height(char **map);
int		get_count(t_mlx *game);
int		ft_close(int keycode, t_mlx *game);

void	long_parse(char *total);
void	ft_render(t_mlx *game);
void	put_sprite(t_mlx *game, int sprite_size);

char	**get_map(int fd);

/*	moving functions	*/

int		ft_move(int keycode, t_mlx *game);
void	move_left(t_mlx *game);
void	move_right(t_mlx *game);
void	move_down(t_mlx *game);
void	move_up(t_mlx *game);

#endif