/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:24:53 by marvin            #+#    #+#             */
/*   Updated: 2023/10/17 20:36:44 by breda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*actual;

	nlst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		actual = ft_lstnew(f(lst->content));
		if (!actual)
		{
			ft_lstclear(&nlst, del);
			return (NULL);
		}
		ft_lstadd_back(&nlst, actual);
		lst = lst->next;
	}
	return (nlst);
}
