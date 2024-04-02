/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:21:36 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 14:21:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char *temp;

	if(ac < 2) 
	{
		write(1, "\n", 1);
		return (0);
	}
	temp = ft_strdup(av[1]);
	if(ac > 2)
	{
		free(temp);
		temp = ft_join_argv(ac, av);
	}
	stack_a = NULL;
	ft_argv_to_stack(temp, &stack_a);
	free(temp);
	ft_check_stack(&stack_a);

	ft_print_stack(stack_a, stack_b);
	//ft_sort_stack(&stack_a, &stack_b);
	ft_clear_stack(&stack_a);

	
	return (0);
}