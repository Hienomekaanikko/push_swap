/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:48:55 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/28 12:12:58 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_index(t_list **stack_src, t_list **stack_dst)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		pos;

	temp_a = *stack_src;
	temp_b = *stack_dst;
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

void	count_cost(t_list **stack_src, t_list **stack_dst, int *size_src, int *size_dst)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		cost;
	int		a_med;
	int		b_med;

	temp_a = *stack_src;
	a_med = *size_src / 2;
	b_med = *size_dst / 2;
	add_index(stack_src, stack_dst);
	while(temp_a)
	{
		temp_b = *stack_dst;
		cost = temp_a->index;
		if (temp_a->index > a_med)
			cost = *size_src - temp_a->index;
		while (temp_b)
		{
			if (*(long long *)temp_b->content == temp_a->target)
				break ;
			if (temp_b->index > b_med)
			{
				cost = *size_dst - temp_b->index;
				temp_b->reverse_roll = 1;
			}
			cost++;
			temp_b = temp_b->next;
		}
		temp_a->cost = cost;
		temp_a = temp_a->next;
	}
}
