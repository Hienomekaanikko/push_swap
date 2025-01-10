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

static void	assign(int min, int max, t_list *temp_a)
{
	int		a_value;

	while (temp_a)
	{
		a_value = *(int *)temp_a->content;
		if ((a_value - max) < (a_value - min) && (a_value - max) > 0)
			temp_a->target = max;
		else if ((a_value - min) > 0)
			temp_a->target = min;
		else
			temp_a->target = max;
		temp_a = temp_a->next;
	}
}

void	add_targets(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		first;
	int		second;
	int		min;
	int		max;

	temp_a = *stack_a;
	temp_b = *stack_b;
	if (!temp_a && !temp_b)
		return ;
	first = *(int *)temp_b->content;
	second = *(int *)temp_b->next->content;
	if (first > second)
	{
		max = first;
		min = second;
	}
	else
	{
		max = second;
		min = first;
	}
	assign(min, max, temp_a);
}
