/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:48:55 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/29 10:28:44 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_index(t_list **stack_src, t_list **stack_dst)
{
	t_list	*temp_src;
	t_list	*temp_dst;
	int		pos;

	temp_src = *stack_src;
	temp_dst = *stack_dst;
	pos = 0;
	while (temp_src)
	{
		temp_src->index = pos;
		pos++;
		temp_src = temp_src->next;
	}
	pos = 0;
	while (temp_dst)
	{
		temp_dst->index = pos;
		pos++;
		temp_dst = temp_dst->next;
	}
}

void	count_cost(t_list **stack_src, t_list **stack_dst)
{
	t_list	*temp_src;
	t_list	*temp_dst;
	int		cost;

	temp_src = *stack_src;
	add_index(stack_src, stack_dst);
	while(temp_src)
	{
		temp_dst = *stack_dst;
		cost = temp_src->index;
		while (temp_dst)
		{
			if (*(long long *)temp_dst->content == temp_src->target)
				break ;
			cost++;
			temp_dst = temp_dst->next;
		}
		temp_src->cost = cost;
		temp_src = temp_src->next;
	}
}
