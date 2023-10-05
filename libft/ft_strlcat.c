/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:11:23 by marvin            #+#    #+#             */
/*   Updated: 2023/09/28 10:11:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	res;
	size_t	j;

	res = ft_strlen(dest);
	if (size < ft_strlen(dest))
		return(size + ft_strlen(src));
	j = 0;
	while (src[j] && (j + res) < size - 1)
	{
		dest[res + j] = (char)src[j];
		j++;
	}
	dest[res + j] = '\0';
	return (res + ft_strlen(src));
}
