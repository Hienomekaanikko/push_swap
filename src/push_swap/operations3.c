/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:09:45 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/14 17:46:50 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	lowest(t_stack **stack)
{
	t_stack		*temp_stack;
	long long	temp;

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

long long	highest(t_stack **stack)
{
	t_stack		*temp_stack;
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

void	rotate_min_on_top(t_stack **stack)
{
	t_stack		*temp;
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

void	ft_add_node(t_stack **stack, long long content)
{
	t_stack		*new_node;
	t_stack		*temp;
	long long	*content_copy;

	if (!stack)
		return ;
	content_copy = malloc(sizeof(long long));
	if (!content_copy)
		return ;
	*content_copy = content;
	new_node = ft_lstnew(content_copy);
	if (!new_node)
	{
		free(content_copy);
		return ;
	}
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}
