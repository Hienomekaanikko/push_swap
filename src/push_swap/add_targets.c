/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:08:30 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/29 14:18:48 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_targets(t_list **stack_a, t_list **stack_b, int mode)
{
	t_list		*temp_a;
	t_list		*temp_b;
	long long	temp;
	long long	min;
	long long	max;

	max = highest(stack_b);
	min = lowest(stack_b);
	temp_a = *stack_a;
	while (temp_a)
	{
		if (mode == 'a')
			temp = min;
		else if (mode == 'b')
			temp = max;
		temp_b = *stack_b;
		while (temp_b)
		{
			if (*(long long*)temp_b->content < *(long long*)temp_a->content && mode == 'a')
			{
				if (*(long long*)temp_b->content > temp)
					temp = *(long long *)temp_b->content;
			}
			else if (*(long long *)temp_b->content > *(long long *)temp_a->content && mode == 'b')
			{
				if (*(long long *)temp_b->content < temp)
					temp = *(long long *)temp_b->content;
			}
			temp_b = temp_b->next;
		}
		if (temp > *(long long *)temp_a->content && mode =='a')
			temp = max;
		if (temp < *(long long *)temp_a->content && mode =='b')
			temp = min;
		temp_a->target = temp;
		temp_a = temp_a->next;
	}
}
