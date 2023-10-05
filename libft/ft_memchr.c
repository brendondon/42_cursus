/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:34:17 by marvin            #+#    #+#             */
/*   Updated: 2023/10/01 15:34:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *src;
	size_t i;

	i = 0;
	src = (const unsigned char *)s;
	while (i < n)
	{
		if(c == src[i])
			return (&src[i]);
		i++;
	}
	return (NULL);
}