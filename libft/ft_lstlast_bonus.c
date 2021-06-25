/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:47:58 by ichougra          #+#    #+#             */
/*   Updated: 2021/06/23 11:32:03 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*elem;

	if (!lst)
		return (NULL);
	elem = lst;
	while (elem->next != NULL)
		elem = elem->next;
	return (elem);
}
