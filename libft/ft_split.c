/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:14:49 by marvin            #+#    #+#             */
/*   Updated: 2023/10/07 10:08:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
	return (0);
}

size_t	cont_w(char const *s, char c)
{
	int		i;
	size_t	count;

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

int	splitstr(char const *s, char **new, char c)
{
	size_t	i;
	size_t	j;
	size_t	v;

	i = 0;
	j = 0;
	v = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] != c)
		{
			while (s[i + j] != c && s[i + j])
				j++;
			new[v] = ft_substr(s, i, j);
			if (!new[v])
				return (ft_free(new, v));
			v++;
			i = i + j;
		}
		else
			i++;
	}
	new[v] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**new;

	new = (char **)malloc(sizeof(char *) * (cont_w(s, c) + 1));
	if (!new)
		return (NULL);
	if (splitstr(s, new, c) == 0)
		return (NULL);
	return (new);
}
