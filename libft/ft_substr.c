/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:51:07 by ichougra          #+#    #+#             */
/*   Updated: 2021/01/11 12:51:08 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	c;
	size_t	n;

	p = malloc(len + 1 * sizeof(char));
	if (p == NULL)
		return (NULL);
	c = 0;
	n = 0;
	while (s[n])
		n++;
	if (start > n)
		len = 0;
	while (c < len && s[start + c] != '\0')
	{
		p[c] = s[start + c];
		c++;
	}
	p[c] = '\0';
	return (p);
}
