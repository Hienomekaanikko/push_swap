/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:08:30 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/28 12:02:13 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_targets_a(t_list **stack_a, t_list **stack_b)
{
	t_list		*temp_a;
	t_list		*temp_b;
	long long	temp;
	long long	min;
	long long	max;

	max = highest(stack_b);
	min = lowest(stack_b);
	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_a)
	{
		temp = min;
		temp_b = *stack_b;
		while (temp_b)
		{
			if (*(long long*)temp_b->content < *(long long*)temp_a->content)
			{
				if (*(long long*)temp_b->content > temp)
					temp = *(long long *)temp_b->content;
			}
			temp_b = temp_b->next;
		}
		if (temp > *(long long *)temp_a->content)
			temp = max;
		temp_a->target = temp;
		temp_a = temp_a->next;
	}
}

void	add_targets_b(t_list **stack_a, t_list **stack_b)
{
	t_list		*temp_a;
	t_list		*temp_b;
	long long	min;
	long long	max;
	long long	temp;

	max = highest(stack_a);
	min = lowest(stack_a);
	temp_b = *stack_b;
	while (temp_b)
	{
		temp = max;
		temp_a = *stack_a;
		while (temp_a)
		{
			if (*(long long *)temp_a->content > *(long long *)temp_b->content && *(long long *)temp_a->content < temp)
				temp = *(long long *)temp_a->content;
			temp_a = temp_a->next;
		}
		if (temp < *(long long *)temp_b->content)
			temp = min;
		temp_b->target = temp;
		temp_b = temp_b->next;
	}
}
