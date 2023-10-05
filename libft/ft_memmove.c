/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:57:42 by marvin            #+#    #+#             */
/*   Updated: 2023/09/27 21:57:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *original;
	unsigned char *copia;

	original = (unsigned char *)src;
	copia = (unsigned char *)dest;

	if(copia > original)
		while(n > 0)
		{
			copia[n - 1] = original[n - 1];
			n--;
		}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}