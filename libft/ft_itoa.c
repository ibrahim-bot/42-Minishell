/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:20:55 by ichougra          #+#    #+#             */
/*   Updated: 2021/06/23 11:30:34 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	itoa_isnegative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

void	ft_itoa_bis(char *str, int len, int n, int neg)
{
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
}

char	*ft_strdup_map(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
	{
		i++;
	}
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		tmp;
	int		len;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup_map("-2147483648"));
	tmp = n;
	len = 2;
	neg = 0;
	itoa_isnegative(&n, &neg);
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	len = len + neg;
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	str[--len] = '\0';
	ft_itoa_bis(str, len, n, neg);
	return (str);
}
