/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:46:46 by ichougra          #+#    #+#             */
/*   Updated: 2021/01/11 12:46:48 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	tsize;

	tsize = count * size;
	ptr = malloc(tsize);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, tsize);
	return (ptr);
}
