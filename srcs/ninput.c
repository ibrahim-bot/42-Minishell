/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ninput.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:55:17 by agachet           #+#    #+#             */
/*   Updated: 2021/06/30 11:27:34 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back_n(t_list **env, char *str)
{
	t_list	*new;
	t_list	*tmp;

	if (!(new = malloc(sizeof(new))))
		exit (EXIT_FAILURE);
	if (*env == NULL)
	{
		new->str = str;
		new->next = NULL;
		(*env) = new;
	}
	else
	{
		new->str = str;
		new->next = NULL;
		tmp = (*env);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_list	**ft_readline(char *str2, t_list **test)
{
	char	*str;

	test = malloc(sizeof(t_list *) * 4086);
	str = " ";
	while (strcmp(str, str2) != 0)
	{   
		str = readline("> ");
		if ((strcmp(str, str2) != 0))
			ft_lstadd_back_n(test, str);
	}
	return (test);
}

void	ft_redi(t_token *token)
{
	t_token	*tmp;
	t_list	**res;
	t_list	**test;

	test = NULL;
	tmp = token;
	res = ft_readline(tmp->str, test);
}