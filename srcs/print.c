/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:46:06 by ichougra          #+#    #+#             */
/*   Updated: 2021/06/25 16:48:00 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_mess(t_token *token)
{
	ft_putstr_fd("bash: syntax error near unexpected token `", STDERR);
	ft_putstr_fd(token->str, STDERR);
	ft_putendl_fd("'", STDERR);
}
