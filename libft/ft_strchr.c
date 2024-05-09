/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:41:47 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/09 14:37:07 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	size_t			len;
	unsigned char	chr;

	chr = c;
	i = 0;
	len = ft_length(s);
	while (i <= len)
	{
		if (s[i] == chr)
			return ((char *)(s + i));
		else
			i++;
	}
	return (0);
}
