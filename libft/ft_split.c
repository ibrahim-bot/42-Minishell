/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:39:53 by ichougra          #+#    #+#             */
/*   Updated: 2021/06/23 12:00:37 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		count++;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c)
			i++;
	}
	return (count);
}

static int	letter_count(char const *s, char c, int index)
{
	int	count;

	count = 0;
	while (s[index] != c && s[index] != '\0')
	{
		count++;
		index++;
	}
	return (count);
}

int	retu_k(char const *s, char c, int k)
{
	while (s[k] == c)
		k++;
	return (k);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	tab = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s || !c || !(tab))
		return (NULL);
	k = retu_k(s, c, k);
	while (s[k] != '\0')
	{
		j = 0;
		tab[i] = malloc(sizeof(char) * letter_count(s, c, k) + 1);
		if (!(tab[i]))
			return (NULL);
		while (s[k] != c && s[k] != '\0')
			tab[i][j++] = s[k++];
		tab[i][j] = '\0';
		k = retu_k(s, c, k);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
