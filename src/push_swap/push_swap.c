/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:32:09 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/10 15:52:24 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_list **stack, int content)
{
	t_list	*new_node;
	t_list	*temp;
	int		*content_copy;

	content_copy = malloc(sizeof(int));
	if (!content_copy)
		return ;
	*content_copy = content;
	new_node = ft_lstnew(content_copy);
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	push_swap(t_list **stack_a)
{
	t_list	*stack_b;
	t_list	*temp;
	int		count;
	int		length;

	stack_b = NULL;
	count = 0;
	length = ft_lstsize(*stack_a);
	if (length == 4)
		pb(stack_a, &stack_b);
	else if (length > 3)
	{
		while (count < 2)
		{
			pb(stack_a, &stack_b);
			count++;
		}
	}
	add_targets(stack_a, &stack_b);
	count_cost(stack_a, &stack_b);
	temp = stack_b;
	ft_printf("Stack B: \n");
	while (temp)
	{
		ft_printf("VALUE: %d, ", *(int *)temp->content);
		ft_printf("INDEX: %d ", temp->index);
		ft_printf("COST: %d ", temp->cost);
		ft_printf("\n");
		temp = temp->next;
	}
	find_cheapest(stack_a);
	ft_printf("\n");
}

int	main(int argc, char *argv[])
{
	int		i;
	t_list	*stack_a;
	t_list	*temp;

	i = 1;
	stack_a = NULL;
	if (argc > 1)
	{
		while (argv[i])
		{
			add_node(&stack_a, ft_atoi(argv[i]));
			i++;
		}
		push_swap(&stack_a);
	}
	temp = stack_a;
	ft_printf("%s\n", "Stack A: ");
	while (temp)
	{
		ft_printf("VALUE: %d, ", *(int *)temp->content);
		ft_printf("TARGET: %d ", temp->target);
		ft_printf("INDEX: %d ", temp->index);
		ft_printf("COST: %d ", temp->cost);
		ft_printf("\n");
		temp = temp->next;
	}
	ft_printf("\n");
	return (0);
}
