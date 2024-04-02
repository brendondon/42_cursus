/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:59:27 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 15:59:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_calloc(size_t count, size_t size)
{
	char *new;
	size_t i;

	i = 0;
	new = (char *)malloc(count * size);
	if (!new)
		return (NULL);
	while (i < count * size)
	{
		new[i] = 0;
		i++;
	}
	return (new);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				index;
	const unsigned char	*original;
	unsigned char		*copia;

	original = (unsigned char *)src;
	copia = (unsigned char *)dest;
	if (!original && !copia)
		return (0);
	index = 0;
	while (index < n)
	{
		copia[index] = original[index];
		index++;
	}
	return (dest);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	res;
	size_t	j;

	res = ft_strlen(dest);
	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	j = 0;
	while (src[j] && (j + res) < size - 1)
	{
		dest[res + j] = (char)src[j];
		j++;
	}
	dest[res + j] = '\0';
	return (res + ft_strlen(src));
}

char	*ft_strdup(const char *s)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)ft_calloc(sizeof(char), size);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, ft_strlen(s1));
	ft_strlcat(new, s2, size + 1);
	return (new);
} 