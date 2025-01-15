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
	t_list	*temp;
	int		count;
	int		a_size;

	stack_b = NULL;
	count = 0;
	a_size = ft_lstsize(*stack_a);
	if (a_size > 3)
	{
		if (a_size == 4)
			pb(stack_a, &stack_b);
		else
		{
			short_sort(stack_a);
			while (count < 2)
			{
				pb(stack_a, &stack_b);
				count++;
			}
		}
		add_targets(stack_a, &stack_b);
		count_cost(stack_a, &stack_b);
		long_sort(stack_a, &stack_b);
		//empty_b_to_a(stack_a, &stack_b);
	}
	else
		short_sort(stack_a);
	temp = stack_b;
	ft_printf("Stack B: \n");
	while (temp)
	{
		ft_printf("VALUE: %d, ", *(int *)temp->content);
		ft_printf("TARGET: %d ", temp->target);
		ft_printf("INDEX: %d ", temp->index);
		ft_printf("COST: %d ", temp->cost);
		ft_printf("\n");
		temp = temp->next;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*temp;
	int		i;

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
