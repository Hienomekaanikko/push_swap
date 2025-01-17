/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:32:09 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/17 19:09:24 by msuokas          ###   ########.fr       */
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
	new_node->reverse_roll = 0;
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

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int		count;
	int		size_a;
	int		size_b;
	int		min;
	int		max;
	t_list	*temp;

	count = 0;
	size_a = ft_lstsize(*stack_a);
	size_b = 0;
	if (size_a > 3)
	{
		if (size_a == 4)
		{
			pb(stack_a, stack_b);
			size_b++;
		}
		else
		{
			short_sort(stack_a);
			while (count < 2)
			{
				pb(stack_a, stack_b);
				count++;
				size_b++;
				size_a--;
			}
		}
		min = lowest(stack_b);
		max = highest(stack_b);
		add_targets_a(stack_a, stack_b, min, max);
		count_cost(stack_a, stack_b, &size_a, &size_b);
		long_sort(stack_a, stack_b, &size_a, &size_b);
	}
	else
		short_sort(stack_a);
	temp = *stack_b;
	ft_printf("STACK_B:\n");
	while (temp)
	{
		ft_printf("Value: %d ", *(int*)temp->content);
		ft_printf("Target: %d ", temp->target);
		ft_printf("Cost: %d \n", temp->cost);
		temp = temp->next;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		while (*++argv)
			add_node(&stack_a, ft_atoi(*argv));
		if (error_check(&stack_a))
		{
			ft_putendl_fd("Error\n", 2);
			return (0);
		}
		push_swap(&stack_a, &stack_b);
	}
	temp = stack_a;
	ft_printf("STACK_A:\n");
	while (temp)
	{
		ft_printf("Value: %d ", *(int*)temp->content);
		ft_printf("Target: %d ", temp->target);
		ft_printf("Cost: %d \n", temp->cost);
		temp = temp->next;
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
