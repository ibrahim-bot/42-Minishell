/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:48:44 by ichougra          #+#    #+#             */
/*   Updated: 2021/06/23 11:35:22 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	str1;
	unsigned char	str2;

	while (n--)
	{
		str1 = *(unsigned char *)s1;
		str2 = *(unsigned char *)s2;
		if (str1 != str2)
			return (str1 - str2);
		s1++;
		s2++;
	}
	return (0);
}
