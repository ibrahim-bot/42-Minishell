/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 19:41:37 by ichougra          #+#    #+#             */
/*   Updated: 2021/06/25 18:33:12 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

char	*space_alloc(char *line)
{
	char	*new;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (is_sep(line, i))
			count++;
		i++;
	}
	new = malloc(sizeof(char) * (i + 2 * count + 1));
	if (!(new))
		return (NULL);
	return (new);
}

char	*space_line(char *line)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = space_alloc(line);
	while (new && line[i])
	{
		if (quotes(line, i) != 2 && line[i] == '$' && i && line[i - 1] != '\\')
			new[j++] = (char)(-line[i++]);
		else if (quotes(line, i) == 0 && is_sep(line, i))
		{
			new[j++] = ' ';
			new[j++] = line[i++];
			if (quotes(line, i) == 0 && (line[i] == '>' || line[i] == '<'))
				new[j++] = line[i++];
			new[j++] = ' ';
		}
		else
			new[j++] = line[i++];
	}
	new[j] = '\0';
	ft_memdel(line);
	return (new);
}

int	quote_check(t_mini *mini, char **line)
{
	if (quotes(*line, 2147483647))
	{
		ft_putendl_fd("minishell: syntax error with open quotes", STDERR);
		ft_memdel(*line);
		mini->ret = 2;
		mini->start = NULL;
		return (1);
	}
	return (0);
}

void	test_line(char *line, t_mini *mini)
{
	ft_memdel(line);
	squish_args(mini);
}

char 	*historic(void)
{
	char	*line;

	line = readline("\033[0;36m\033[1mminishell ▸ \033[0m");
	if (line && ft_strlen(line) != 0)
		add_history(line);
	return (line);
}

int	empty_line(char *line)
{
	if (line == NULL)
		return (1);
	return (0);
}

void	parse(t_mini *mini)
{
	char	*line;
	t_token	*token;

	line = historic();
	if (empty_line(line) == 1)
	{
		line = malloc(sizeof(char) * 1);
		mini->exit = 1;
		printf("\r\033[0;36m\033[1mminishell ▸ \033[0m");
		printf("exit\n");
	}
	if (g_sig.sigint == 1)
		mini->ret = g_sig.exit_status;
	if (quote_check(mini, &line))
		return ;
	line = space_line(line);
	if (line && line[0] == '$')
		line[0] = (char)(-line[0]);
	mini->start = get_tokens(line);
	test_line(line, mini);
	token = mini->start;
	while (token)
	{
		if (is_type(token, ARG))
			type_arg(token, 0);
		token = token->next;
	}
}
