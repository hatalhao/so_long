/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:16:47 by hatalhao          #+#    #+#             */
/*   Updated: 2024/05/10 17:10:45 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_atoi(char const *nptr);
int		ft_strcmp(const char *s1, const char *s2);

int		ft_printf(char const *str, ...);

char	*get_next_line(int fd);
char	*ft_strdup(char const *src);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);

char	**ft_split(char const *s, char c);

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	str_fd(char *s, int fd);

#endif
