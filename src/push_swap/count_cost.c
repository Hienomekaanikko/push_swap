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
	int		temp_index_a;
	int		cost;

	add_index(stack_a, stack_b);
	temp_a = *stack_a;
	while (temp_a)
	{
		temp_b = *stack_b;
		temp_index_a = temp_a->index;
		cost = 0;
		while (temp_index_a != 0)
		{
			cost++;
			temp_index_a--;
		}
		while (*(int*)temp_b->content != temp_a->target)
		{
			cost++;
			temp_b = temp_b->next;
		}
		temp_a->cost = cost;
		temp_a = temp_a->next;
	}
}
