/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:14:37 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/14 16:19:03 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_dst(t_stack **stack, t_data *data)
{
	if (data->dst_index <= data->dst_median)
	{
		if (data->stack_flag == 'a')
			rotate(stack, "rb");
		else
			rotate(stack, "ra");
		data->dst_index--;
	}
	else if (data->dst_index > data->dst_median)
	{
		if (data->stack_flag == 'a')
			reverse(stack, "rrb");
		else
			reverse(stack, "rra");
		data->dst_index++;
	}
}

static void	rotate_src(t_stack **stack, t_data *data)
{
	if (data->src_index <= data->src_median)
	{
		if (data->stack_flag == 'a')
			rotate(stack, "ra");
		else
			rotate(stack, "rb");
		data->src_index--;
	}
	else if (data->dst_index == 0 && data->src_index > data->src_median)
	{
		if (data->stack_flag == 'a')
			reverse(stack, "rra");
		else
			reverse(stack, "rrb");
		data->src_index++;
	}
}

static void	position(t_stack **src, t_stack **dst, t_data *data)
{
	while (*(*dst)->content != (*src)->target)
	{
		if (data->src_index == data->src_size)
			data->src_index = 0;
		if (data->dst_index == data->dst_size)
			data->dst_index = 0;
		if ((data->src_index > 0 && data->dst_index > 0)
			&& (data->src_index <= data->src_median
				&& data->dst_index <= data->dst_median))
			rot_both(src, dst, "rr", data);
		else if ((data->src_index > data->src_median
				&& data->dst_index > data->dst_median))
			rev_both(src, dst, "rrr", data);
		else if (data->src_index >= 0 && data->dst_index > 0)
			rotate_dst(dst, data);
		else if (data->dst_index >= 0 && data->src_index > 0)
			rotate_src(src, data);
	}
}

void	fill(t_stack **src, t_stack **dst, t_data *data)
{
	while (data->src_size > data->limit)
	{
		update_values(src, dst, data);
		position(src, dst, data);
		if (data->stack_flag == 'a')
			push(src, dst, "pb");
		else
			push(src, dst, "pa");
		data->src_size--;
		data->dst_size++;
	}
}
