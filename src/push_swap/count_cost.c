/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:48:55 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/10 14:17:28 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//count the cost to find the cheapest one and add the cost to the node information to compare

#include "push_swap.h"

void	add_index(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		pos;

	temp_a = *stack_a;
	temp_b = *stack_b;
	pos = 0;
	while (temp_a)
	{
		temp_a->index = pos;
		pos++;
		temp_a = temp_a->next;
	}
	pos = 0;
	while (temp_b)
	{
		temp_b->index = pos;
		pos++;
		temp_b = temp_b->next;
	}
}

void	count_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		cost;
	int		a_med;
	int		b_med;

	temp_a = *stack_a;
	a_med = ft_lstsize(*stack_a) / 2;
	b_med = ft_lstsize(*stack_b) / 2;
	add_index(stack_a, stack_b);
	while(temp_a)
	{
		temp_b = *stack_b;
		cost = temp_a->index;
		if (temp_a->index > a_med)
			cost = ft_lstsize(*stack_a) - temp_a->index;
		while (temp_b)
		{
			if (*(int *)temp_b->content == temp_a->target)
				break ;
			if (temp_b->index > b_med)
			{
				cost = ft_lstsize(*stack_b) - temp_b->index;
				temp_b->reverse_roll = 1;
			}
			cost++;
			temp_b = temp_b->next;
		}
		temp_a->cost = cost;
		temp_a = temp_a->next;
	}
}
