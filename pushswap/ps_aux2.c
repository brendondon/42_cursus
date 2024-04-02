/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_aux2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:23:05 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 18:23:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sig;
	int		nbr;

	i = 0;
	nbr = 0;
	sig = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sig = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + nptr[i] - '0';
		i++;
	}
	return (nbr * sig);
}

t_list	*ft_lstnew(int data)
{
	t_list	*newl;

	newl = (t_list *)malloc(sizeof(*newl));
	if (!newl)
		return (NULL);
	newl->data = data;
	newl->next = NULL;
	return (newl);
}
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		if (!temp->next)
			return (temp);
		temp = temp->next;
	}
	return (temp);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
	else
	{
		*lst = new;
	}
}
