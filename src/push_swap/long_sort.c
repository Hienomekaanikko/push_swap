/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:14:37 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/03 10:46:59 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	position(t_list **stack_src, t_list **stack_dst, t_data *data)
{
	while (*(*stack_dst)->content != (*stack_src)->target)
	{
		if (data->src_index == data->src_size)
			data->src_index = 0;
		if (data->dst_index == data->dst_size)
			data->dst_index = 0;
		if ((data->src_index > 0 && data->dst_index > 0)
			&& (data->src_index <= data->src_median && data->dst_index <= data->dst_median))
			rotate_both(stack_src, stack_dst, "rr", data);
		else if ((data->src_index > data->src_median && data->dst_index > data->dst_median)
			&& (data->src_index < data->src_size && data->dst_index < data->dst_size))
			reverse_both(stack_src, stack_dst, "rrr", data);
		else if (data->src_index == 0 && data->dst_index > 0)
			rotate_dst(stack_dst, data);
		else if (data->dst_index == 0 && data->src_index > 0)
			rotate_src(stack_src, data);
		else if (data->src_index == 0 && data->dst_index > data->dst_median)
			reverse_dst(stack_dst, data);
		else if (data->dst_index == 0 && data->src_index > data->src_median)
			reverse_src(stack_src, data);
		else
			other_case(stack_src, data);
	}
}

static void	fill(t_list **stack_src, t_list **stack_dst, t_data *data)
{
	while(data->src_size > data->limit)
	{
		data->highest = highest(stack_dst);
		data->lowest = lowest(stack_dst);
		add_targets(stack_src, stack_dst, data);
		data->cheapest = find_cheapest(stack_src);
		data->src_median = data->src_size / 2;
		data->dst_median = data->dst_size / 2;
		data->src_index = src_to_top_dist(data->cheapest, stack_src);
		data->dst_index = dst_to_top_dist(data->cheapest, stack_src, stack_dst);
		if (data->src_index == 0 && data->dst_index == 0 && data->stack_flag == 'a')
			push(stack_src, stack_dst, "pb");
		else if (data->src_index == 0 && data->dst_index == 0 && data->stack_flag == 'b')
			push(stack_src, stack_dst, "pa");
		else
		{
			position(stack_src, stack_dst, data);
			if (data->stack_flag == 'a')
				push(stack_src, stack_dst, "pb");
			else
				push(stack_src, stack_dst, "pa");
		}
		data->src_size--;
		data->dst_size++;
	}
}

void	long_sort(t_list **stack_a, t_list **stack_b)
{
	t_data	data;
	t_list	*temp_a;

	temp_a = *stack_b;
	if (!temp_a)
		return ;
	data.stack_flag = 'a';
	data.limit = 2;
	data.src_size = ft_lstsize(*stack_a);
	data.dst_size = ft_lstsize(*stack_b);
	fill(stack_a, stack_b, &data);
	data.limit = 0;
	data.stack_flag = 'b';
	data.src_size = ft_lstsize(*stack_b);
	data.dst_size = ft_lstsize(*stack_a);
	fill(stack_b, stack_a, &data);
	rotate_min_on_top(stack_a);
}
