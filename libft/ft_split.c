/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:14:49 by marvin            #+#    #+#             */
/*   Updated: 2023/10/05 10:50:44 by breda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t cont_w(char const *s, char c)
{
	int i;
	size_t count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char **ft_split(char const *s, char c)
{
	char **new;
	size_t v;
	size_t i;
	size_t j;

	i = 0;
	v = 0;
	if (!(new = (char **)malloc(sizeof(char *) * cont_w(s, c) + 1)))
		return (NULL);
	while (s[i])
	{
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j > 0)
		{
			new[v] = ft_substr(s, i, j);
			v++;
		}
		i = i + j + 1;
	}
	new[v] = NULL;
	return (new);
}