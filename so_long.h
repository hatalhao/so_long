/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:20:33 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/10 18:58:24 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <math.h>
# include <mlx.h>

typedef struct s_mlx
{
	void				*mlx;
	void				*window;
	void				*wall;
	void				*floor;
	char				**map;
	char				**map_dup;
	char				*addr;
	int					height;
	int					width;
	void				*player;
	void				*exit;
	void				*collectible;
	int					p_x;
	int					p_y;
	int					moves;
	int					e_count;
	int					p_count;
	int					c_count;
}						t_mlx;

# define MAX_WIDTH 2560
# define MAX_HEIGHT 1440
# define SPRITE_SIZE 128 // change to 64

/*		so_long.c		*/
int						ft_close(void);
void					free_alloc(t_mlx *game);

/*		the_parse.c		*/
void					the_parse(t_mlx *game, char *av);

void					long_parse(char *total);
void					ft_render(t_mlx *game);
void					put_sprite(t_mlx *game, int sprite_size);
void					print_moves(t_mlx *game);

/*		utiles2.c		*/
char					**map_dup(t_mlx *game);
void					ff_verdict(t_mlx *game);
void					ft_error(char *str, t_mlx *game);
void					ft_flood_fill(char **map, int y, int x);

/*		utiles3.c		*/
char					**get_map(int fd);
int						get_height(char **map);
void					get_count(t_mlx *game);
void					player_coords(t_mlx *game);

/*		moving functions	*/
int						ft_move(int keycode, t_mlx *game);
void					move_left(t_mlx *game);
void					move_right(t_mlx *game);
void					move_down(t_mlx *game);
void					move_up(t_mlx *game);

#endif