/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:42:31 by ichougra          #+#    #+#             */
/*   Updated: 2021/06/24 17:12:23 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cmd_tab(t_token *start)
{
	t_token	*token;
	char	**tab;
	int		i;

	if (!start)
		return (NULL);
	tab = malloc(sizeof(char *) * 4086);
	if (!(tab))
		return (NULL);
	token = start->next;
	tab[0] = start->str;
	i = 1;
	while (token && token->type < TRUNC)
	{
		tab[i++] = token->str;
		token = token->next;
	}
	tab[i] = NULL;
	return (tab);
}

void	exec_cmd(t_mini *mini, t_token *token)
{
	char	**cmd;
	int		i;

	if (mini->charge == 0)
		return ;
	cmd = cmd_tab(token);
	i = 0;
	while (cmd && cmd[i])
	{
		cmd[i] = expansions(cmd[i], mini->env, mini->ret);
		i++;
	}
	if (cmd && ft_strcmp(cmd[0], "exit") == 0 && has_pipe(token) == 0)
		mini_exit(mini, cmd);
	else if (cmd && is_builtin(cmd[0]))
		mini->ret = exec_builtin(cmd, mini);
	else if (cmd)
		mini->ret = exec_bin(cmd, mini->env, mini);
	free_tab(cmd);
	ft_close(mini->pipin);
	ft_close(mini->pipout);
	mini->pipin = -1;
	mini->pipout = -1;
	mini->charge = 0;
}
