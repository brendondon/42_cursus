/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:28:51 by marvin            #+#    #+#             */
/*   Updated: 2024/02/28 15:28:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_stack(t_list *stack_a, t_list *stack_b)
{
	t_list *temp;

	temp = stack_a;
	while(temp)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

void ft_free_split(char **str)
{
	int i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}


char *ft_join_argv(int ac, char **av)
{
	char *temp;
	char *temp2;
	int i;

	i = 2;
	temp = ft_strdup(av[1]);
	while(i < ac)
	{
		temp2 = ft_strjoin(temp, " ");
		free(temp);
		temp = ft_strjoin(temp2, av[i]);
		free(temp2);
		i++;
	}
	return (temp);
}

void ft_argv_to_stack(char *str, t_list **stack)
{
	char **temp;
	int i;

	i = 0;  
	temp = ft_split(str, ' ');
	while(temp[i])
	{
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(temp[i])));
		i++;
	}
	ft_free_split(temp);
}

void	ft_check_stack(t_list **stack)
{
	t_list *temp;
	t_list *temp2;

	temp = *stack;
	while(temp)
	{
		temp2 = temp->next;
		while(temp2)
		{
			if(temp->data == temp2->data)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}
void ft_clear_stack(t_list **stack)
{
	t_list *temp;

	while(*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}