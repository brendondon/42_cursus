/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:37:35 by marvin            #+#    #+#             */
/*   Updated: 2023/10/03 22:37:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *new;
	size_t size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(new = (char *)ft_calloc(size + 1, sizeof(char))))
		return(NULL);
	ft_memcpy(new, s1, ft_strlen(s1));
	ft_strlcat(new, s2, size);
	return(new);	
}