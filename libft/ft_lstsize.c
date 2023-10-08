/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 00:16:53 by marvin            #+#    #+#             */
/*   Updated: 2023/10/08 00:16:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		nl;
	t_list	*cont;

	nl = 0;
	cont = lst;
	while (cont)
	{
		cont = cont->next;
		nl++;
	}
	return (nl);
}
