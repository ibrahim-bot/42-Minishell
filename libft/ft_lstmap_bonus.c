/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:48:05 by ichougra          #+#    #+#             */
/*   Updated: 2021/06/23 11:33:57 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*copie;
	t_list		*deb;

	deb = ft_lstnew(lst->content);
	copie = NULL;
	if (!lst || !(deb))
		return (deb);
	deb->content = f(deb->content);
	copie = deb;
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(lst->content);
		if (!(new))
		{
			ft_lstclear(&copie, del);
			return (NULL);
		}
		new->content = f(new->content);
		deb->next = new;
		deb = deb->next;
		lst = lst->next;
	}
	return (copie);
}
