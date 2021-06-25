/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:50:42 by ichougra          #+#    #+#             */
/*   Updated: 2021/06/23 12:04:42 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0' || (needle[0] == haystack[0] && needle[1] == '\0'))
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (i + j < len && haystack[i + j] && \
					needle[j] == haystack[i + j])
				j++;
			if (needle[j] == '\0')
				return (((char *)haystack) + i);
		}
		i++;
	}
	return (NULL);
}
