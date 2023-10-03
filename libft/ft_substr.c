/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:25:01 by marvin            #+#    #+#             */
/*   Updated: 2023/10/03 21:25:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t size;
	char *new;

	size = ft_strlen(s);
	if (size < len)
		return (NULL);
	if (!(new = (char *)malloc(len + 1)))
		return(NULL);
	ft_strlcpy(new, &s[start], len);
	return(new);
}