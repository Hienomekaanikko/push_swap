/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:08:30 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/10 18:18:05 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign(int temp, t_list **stack_a)
{
	t_list	*temp_a;

	temp_a = *stack_a;
	temp_a->target = temp;
}

void	add_targets(t_list **stack_a, t_list **stack_b)
{
	t_list *temp_a;
	t_list *temp_b;
	int		max;
	int		min;
	int		temp;

	temp_a = *stack_a;
	temp_b = *stack_b;
	max = highest(stack_b);
	min = lowest(stack_b);
	while (temp_a)
	{
		temp = min;
		temp_b = *stack_b;
		while (temp_b)
		{
			if (*(int *)temp_b->content < *(int *)temp_a->content)
			{
				if (*(int *)temp_b->content > temp)
					temp = *(int *)temp_b->content;
			}
			temp_b = temp_b->next;
		}
		if (temp > *(int *)temp_a->content)
			temp = max;
		assign(temp, &temp_a);
		temp_a = temp_a->next;
	}
}
