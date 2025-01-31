/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_orders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:13:41 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/31 12:36:44 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_dst(t_list **stack_dst, t_data *data)
{
	if (data->dst_index <= data->dst_median)
	{
		if (data->stack_flag == 'a')
			rotate(stack_dst, "rb");
		else
			rotate(stack_dst, "ra");
		data->dst_index--;
	}
	else if (data->dst_index > data->dst_median)
	{
		if (data->stack_flag == 'a')
			reverse(stack_dst, "rrb");
		else
			reverse(stack_dst, "rra");
		data->dst_index++;
	}
}

void	rotate_src(t_list **stack_src, t_data *data)
{
	if (data->src_index <= data->src_median)
	{
		if (data->stack_flag == 'a')
			rotate(stack_src, "ra");
		else
			rotate(stack_src, "rb");
		data->src_index--;
	}
	else if (data->dst_index == 0 && data->src_index > data->src_median)
	{
		if (data->stack_flag == 'a')
			reverse(stack_src, "rra");
		else
			reverse(stack_src, "rrb");
		data->src_index++;
	}
}

void reverse_dst(t_list **stack_dst, t_data *data)
{
	if (data->dst_index > data->dst_median)
	{
			if (data->stack_flag == 'a')
				reverse(stack_dst, "rrb");
			else
				reverse(stack_dst, "rra");
			data->dst_index++;
	}
}

void	reverse_src(t_list **stack_src, t_data *data)
{
	if (data->src_index < data->src_size)
	{
		if (data->stack_flag == 'a')
			reverse(stack_src, "rra");
		else
			reverse(stack_src, "rrb");
		data->src_index++;
	}
}
