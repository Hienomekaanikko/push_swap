/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:32:09 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/10 18:14:21 by msuokas          ###   ########.fr       */
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

void	push_swap(t_list **stack_a)
{
	t_list	*stack_b;
	int		count;
	int		length;

	stack_b = NULL;
	count = 0;
	length = ft_lstsize(*stack_a);
	if (length > 3)
	{
		if (length == 4)
			pb(stack_a, &stack_b);
		else
		{
			quick_sort(stack_a);
			while (count < 2)
			{
				pb(stack_a, &stack_b);
				count++;
			}
		}
		add_targets(stack_a, &stack_b);
		count_cost(stack_a, &stack_b);
		build_stack_b(stack_a, &stack_b);
		empty_b_to_a(stack_a, &stack_b);
	}
	else
		quick_sort(stack_a);
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
		if (!error_check(&stack_a))
		{
			ft_printf("error\n");
			return (0);
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
	return (0);
}
