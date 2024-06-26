/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:56:12 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/11 20:55:19 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	long_parse(char *total)
{
	int	i;

	i = 0;
	while (total[i] && total[i + 1])
	{
		if (total[i] == '\n' && total[i + 1] == '\n')
		{
			str_fd("Error:Two or More Consecutive Newlines in The Map\n", 2);
			ft_free(&total);
			exit(1);
		}
		i++;
	}
	if (total[i] == '\n' && total[i + 1] == '\0')
	{
		str_fd("Error: Newline at The End of The Map\n", 2);
		ft_free(&total);
		exit(1);
	}
}
