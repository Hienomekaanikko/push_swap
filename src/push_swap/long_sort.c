/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:14:37 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/31 15:57:56 by msuokas          ###   ########.fr       */
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

static void	fill_b(t_list **stack_src, t_list **stack_dst, int *size_src, int *size_dst)
{
	t_data data;

	while(*size_src > 2)
	{
		data.stack_flag = 'a';
		data.highest = highest(stack_dst);
		data.lowest = lowest(stack_dst);
		add_targets(stack_src, stack_dst, &data);
		data.cheapest = find_cheapest(stack_src);
		data.src_size = *size_src;
		data.dst_size = *size_dst;
		data.src_median = *size_src / 2;
		data.dst_median = *size_dst / 2;
		data.src_index = src_to_top_dist(data.cheapest, stack_src);
		data.dst_index = dst_to_top_dist(data.cheapest, stack_src, stack_dst);
		if (data.src_index == 0 && data.dst_index == 0)
			push(stack_src, stack_dst, "pb");
		else
		{
			position(stack_src, stack_dst, &data);
			push(stack_src, stack_dst, "pb");
		}
		(*size_src)--;
		(*size_dst)++;
	}
}
static void	fill_a(t_list **stack_src, t_list **stack_dst, int *size_src, int *size_dst)
{
	t_data data;

	while (*size_dst > 0)
	{
		data.stack_flag = 'b';
		data.highest = highest(stack_src);
		data.lowest = lowest(stack_src);
		add_targets(stack_dst, stack_src, &data);
		data.cheapest = find_cheapest(stack_dst);
		data.src_size = *size_dst;
		data.dst_size = *size_src;
		data.src_median = *size_src / 2;
		data.dst_median = *size_dst / 2;
		data.src_index = src_to_top_dist(data.cheapest, stack_dst);
		data.dst_index = dst_to_top_dist(data.cheapest, stack_dst, stack_src);
		if (data.src_index == 0 && data.dst_index == 0)
			push(stack_dst, stack_src, "pa");
		else
		{
			position(stack_dst, stack_src, &data);
			push(stack_dst, stack_src, "pa");
		}
		(*size_src)++;
		(*size_dst)--;
	}
}

void	long_sort(t_list **stack_src, t_list **stack_dst, int *size_src, int *size_dst)
{
	t_list	*temp_src;

	temp_src = *stack_src;
	if (!temp_src)
		return ;
	fill_b(stack_src, stack_dst, size_src, size_dst);
	fill_a(stack_src, stack_dst, size_src, size_dst);
	rotate_min_on_top(stack_src);
}
