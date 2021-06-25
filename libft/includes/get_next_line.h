/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:43:21 by ichougra          #+#    #+#             */
/*   Updated: 2021/01/11 12:52:34 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# define BUFFER_SIZE	4096

int		get_next_line(int fd, char **line);
size_t	ft_l(char const *str);
char	*ft_sub(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);

#endif
