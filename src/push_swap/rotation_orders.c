/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_orders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:13:41 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/10 09:12:25 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_dst(t_list **dst, t_data *data)
{
	if (data->dst_index <= data->dst_median)
	{
		if (data->stack_flag == 'a')
			rotate(dst, "rb");
		else
			rotate(dst, "ra");
		data->dst_index--;
	}
	else if (data->dst_index > data->dst_median)
	{
		if (data->stack_flag == 'a')
			reverse(dst, "rrb");
		else
			reverse(dst, "rra");
		data->dst_index++;
	}
}

void	rotate_src(t_list **src, t_data *data)
{
	if (data->src_index <= data->src_median)
	{
		if (data->stack_flag == 'a')
			rotate(src, "ra");
		else
			rotate(src, "rb");
		data->src_index--;
	}
	else if (data->dst_index == 0 && data->src_index > data->src_median)
	{
		if (data->stack_flag == 'a')
			reverse(src, "rra");
		else
			reverse(src, "rrb");
		data->src_index++;
	}
}

void	reverse_dst(t_list **dst, t_data *data)
{
	if (data->dst_index > data->dst_median)
	{
		if (data->stack_flag == 'a')
			reverse(dst, "rrb");
		else
			reverse(dst, "rra");
		data->dst_index++;
	}
}

void	reverse_src(t_list **src, t_data *data)
{
	if (data->src_index < data->src_size)
	{
		if (data->stack_flag == 'a')
			reverse(src, "rra");
		else
			reverse(src, "rrb");
		data->src_index++;
	}
}
