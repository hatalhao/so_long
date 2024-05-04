/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:20:33 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/03 09:49:08 by hatalhao         ###   ########.fr       */
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
	void	*img;
	void	*img_z;
	void	*window;
	char	**map;
	char	*addr;
	int		height;
	int		width;
	void	*player;
	void	*exit;
	void	*collectible;
}				t_mlx;

typedef	struct	s_window
{
	int			height;
	int			width;
}				t_window;

/*		*/

int		get_height(char **map);

void	long_parse(char *total);

char	**get_map(int fd);

#endif