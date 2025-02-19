/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_prep2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:18:58 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/17 18:28:20 by msuokas          ###   ########.fr       */
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

void	init_data_a(t_stack **a, t_stack **b, t_data *data)
{
	data->limit = 2;
	data->stack_flag = 'a';
	data->src_size = ft_lstsize(*a);
	data->dst_size = ft_lstsize(*b);
}

void	init_data_b(t_stack **a, t_stack **b, t_data *data)
{
	data->limit = 0;
	data->stack_flag = 'b';
	data->src_size = ft_lstsize(*b);
	data->dst_size = ft_lstsize(*a);
}
