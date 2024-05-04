/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:56:12 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/01 11:42:06 by hatalhao         ###   ########.fr       */
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
			ft_free(&total);
			// perror(strerror(errno()));
			exit(1);
		}
		i++;
	}
}
