/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:56:12 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/09 23:52:35 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	long_parse(char *total)
{
	int  i;

	i = 0;
	while (total && total[i] && total[i + 1])
	{
		if (total[i] == '\n' && total[i + 1] == '\n')
		{
			ft_putstr_fd("Error : There are two consecutive newlines in the map\n", 2);
			ft_free(&total);
			exit(1);
		}
		else if (total[i] == '\n' && total[i + 1] == '\0')
		{
			ft_putstr_fd("Error : There is a newline at the end of the map\n", 2);
			ft_free(&total);
			exit(1);
		}
		i++;
	}
}
