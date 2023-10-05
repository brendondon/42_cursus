/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:41:18 by marvin            #+#    #+#             */
/*   Updated: 2023/10/05 11:39:37 by breda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	end;
	size_t	start;
	size_t	len;

	start = 0;
	end = ft_strlen(s1);
	while (ft_isset(s1[start], set))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (ft_isset(s1[end - 1], set))
		end--;
	len = end - start;
	new = ft_substr(s1, start, len);
	return (new);
}
