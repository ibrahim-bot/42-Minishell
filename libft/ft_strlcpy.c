/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:50:19 by ichougra          #+#    #+#             */
/*   Updated: 2021/06/23 12:02:07 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_mod(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	if (!dst || !src)
		return (0);
	if (size == 0)
		return (ft_strlen_mod(src));
	while (src[i])
		++i;
	while (src[j] != '\0' && j + 1 < size)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
