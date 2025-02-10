/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:09:45 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/10 09:10:43 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	lowest(t_list **stack)
{
	t_list		*temp_stack;
	long long	temp;

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
	t_list		*temp_stack;
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

void	rotate_min_on_top(t_list **stack)
{
	t_list		*temp;
	int			size;
	int			median;
	int			i;
	long long	target;

	size = ft_lstsize(*stack);
	median = (size + 1) / 2;
	target = lowest(stack);
	temp = *stack;
	while (*temp->content != target)
		temp = temp->next;
	i = temp->index;
	if (i < median)
	{
		while (*(*stack)->content != target)
			rotate(stack, "ra");
	}
	else
	{
		while (*(*stack)->content != target)
			reverse(stack, "rra");
	}
}
