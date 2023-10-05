/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:40:23 by marvin            #+#    #+#             */
/*   Updated: 2023/09/27 21:40:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*original;
	unsigned char	*copia;

	original = (unsigned char *)src;
	copia = (unsigned char *)dest;
	index = 0;
	while (index < n)
	{
		copia[index] = original[index];
		index++;
	}
	return (dest);
}
