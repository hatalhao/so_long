/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:47:22 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/03 05:05:55 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	// long_parse(total);
	// printf("{%s}", total);
	map = ft_split(total, '\n');
	free (total);
	return (map);
}