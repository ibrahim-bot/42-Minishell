/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:49:45 by ichougra          #+#    #+#             */
/*   Updated: 2021/06/23 12:00:08 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i])
		i++;
	if (c == '\0')
		return ((char *)s + i);
	while (s[j] && s[j] != c)
		j++;
	if (j == i)
		return (NULL);
	return ((char *)s + j);
}
