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

void	rotate_min_on_top(t_list **src)
{
	t_list		*temp;
	long long	min;
	int			median;

	min = lowest(src);
	median = ft_lstsize(*src) / 2;
	temp = *src;
	while (*temp->content != min)
		temp = temp->next;
	if (temp->index > median)
	{
		while (*(*src)->content != min)
			reverse(src, "rra");
	}
	else
	{
		while (*(*src)->content != min)
			rotate(src, "ra");
	}
}
