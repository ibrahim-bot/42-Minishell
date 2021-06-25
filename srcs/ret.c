/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:49:05 by ichougra          #+#    #+#             */
/*   Updated: 2021/06/23 15:49:37 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ret_mini(t_mini *mini)
{
	if (mini->start->prev)
		mini->start->prev = mini->start->prev;
	else
		mini->start->prev = mini->start;
	return (mini->start->prev);
}

t_token	*ret_prev(t_token *prev, t_token *token, t_mini *mini)
{
	if (prev)
		token->next = prev->next;
	else
		token->next = mini->start;
	return (token->next);
}

t_token	*ret_next(t_token *prev, t_token *token, t_mini *mini)
{
	if (mini->start->prev)
		prev->next = prev->next;
	else
		prev->next = token;
	return (prev->next);
}
