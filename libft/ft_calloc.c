/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:30:47 by marvin            #+#    #+#             */
/*   Updated: 2023/10/01 18:30:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	unsigned char *new;
	size_t	i;

	i = 0;
	if (!(new = (unsigned char *)malloc(nmemb * size)))
		return(NULL);
	while (i < size)
	{
		new[i] = 0;
		i++;
	}
	return (new);
}