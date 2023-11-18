/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:20:55 by marvin            #+#    #+#             */
/*   Updated: 2023/11/18 21:50:57 by breda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*new;
	size_t	i;

	new = (char *)malloc(nmemb * size);
	if (new == NULL)
		return (new);
	i = 0;
	while (i < size)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}

size_t	ft_charf(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*next_line(char *temp)
{
	char	*ret;
	size_t	i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n' || !temp[i])
			break ;
		i++;
	}
	if ((temp[i] == '\n' && temp[i + 1] == '\0') || temp[i] == '\0')
	{
		free(temp);
		return (NULL);
	}
	else if (temp[i] == '\n')
		i++;
	ret = ft_strdup(&temp[i]);
	free(temp);
	return (ret);
}
