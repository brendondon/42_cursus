/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:37:41 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 19:37:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	ft_push(t_list **from, t_list **to)
{
	t_list	*temp;

	if (!*from)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
}

void	ft_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp2 = *stack;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = temp;
	temp->next = NULL;
}

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	temp2 = temp->next;
	temp->next = NULL;
	temp2->next = *stack;
	*stack = temp2;
}

