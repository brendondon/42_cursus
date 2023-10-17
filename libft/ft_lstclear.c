/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:50:10 by marvin            #+#    #+#             */
/*   Updated: 2023/10/17 19:49:00 by breda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nlist;
	t_list	*actual;

	actual = *lst;
	while (actual)
	{
		nlist = actual->next;
		ft_lstdelone(actual, del);
		actual = nlist;
	}
	*lst = NULL;
}
