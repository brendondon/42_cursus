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

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*new;
	size_t			i;

	i = 0;
	new = (unsigned char *)malloc(nmemb * size);
	if (!new)
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
