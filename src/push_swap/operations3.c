/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:09:45 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/31 11:04:16 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long lowest(t_list **stack)
{
	t_list *temp_stack;
	long long temp;

	if (!stack || !*stack)
		return (0);

	temp_stack = *stack;
	temp = *temp_stack->content;
	while (temp_stack)
	{
		if (*temp_stack->content < temp)
			temp = *temp_stack->content;
		temp_stack = temp_stack->next;
	}
	return (temp);
}

long long	highest(t_list **stack)
{
	t_list	*temp_stack;
	long long	temp;

	temp_stack = *stack;
	temp = *temp_stack->content;
	while (temp_stack)
	{
		if (*temp_stack->content > temp)
			temp = *temp_stack->content;
		temp_stack = temp_stack->next;
	}
	return (temp);
}

void	rotate_max_on_top(t_list **stack_src)
{
	long long	target;

	target = highest(stack_src);
	while (*(*stack_src)->content != target)
		rotate(stack_src, "rb");
}

void	rotate_min_on_top(t_list **stack_src)
{
	long long	target;

	target = lowest(stack_src);
	while (*(*stack_src)->content != target)
		rotate(stack_src, "ra");
}
