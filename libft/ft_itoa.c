/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:17:56 by marvin            #+#    #+#             */
/*   Updated: 2023/10/04 22:17:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	cont_int(int n)
{
	size_t	cont;

	cont = 0;
	if (n == -2147483647)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		cont++;
		n = n * (-1);
	}
	if (n > 9)
	{
		while (n > 9)
		{
			cont++;
			n = n / 10;
		}
	}
	return (cont + 1);
}

void	fill_wint(char *new, int n, int len)
{
	size_t	i;

	i = len;
	if (n < 0)
	{
		new[0] = '-';
		n = n * (-1);
		len = len - 1;
	}
	while (len > 0)
	{
		new[i] = n % 10 + '0';
		n = n / 10;
		i--;
		len--;
	}
	new[i] = n + '0';
}

char	*ft_itoa(int n)
{
	char	*new;
	size_t	len;

	len = cont_int(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	new = (char *)ft_calloc(sizeof(char), len + 1);
	if (!new)
		return (NULL);
	fill_wint(new, n, len - 1);
	return (new);
}
