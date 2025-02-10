/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:14:37 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/10 10:09:19 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reset_distance(t_data *data)
{
	if (data->src_index == data->src_size)
		data->src_index = 0;
	if (data->dst_index == data->dst_size)
		data->dst_index = 0;
}

static void	position(t_list **src, t_list **dst, t_data *data)
{
	while (*(*dst)->content != (*src)->target)
	{
		if (data->src_index == data->src_size
			|| data->dst_index == data->dst_size)
			reset_distance(data);
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

static void	fill(t_list **src, t_list **dst, t_data *data)
{
	while (data->src_size > data->limit)
	{
		data->highest = highest(dst);
		data->lowest = lowest(dst);
		add_index(src);
		add_index(dst);
		data->src_median = data->src_size / 2;
		data->dst_median = data->dst_size / 2;
		add_targets(src, dst, data);
		data->cheapest = find_cheapest(src);
		data->src_index = src_to_top_dist(data->cheapest, src);
		data->dst_index = dst_to_top_dist(data->cheapest, src, dst);
		position(src, dst, data);
		if (data->stack_flag == 'a')
			push(src, dst, "pb");
		else
			push(src, dst, "pa");
		data->src_size--;
		data->dst_size++;
	}
}

void	long_sort(t_list **a, t_list **b)
{
	t_data	data;
	t_list	*temp_a;

	temp_a = *b;
	if (!temp_a)
		return ;
	data.stack_flag = 'a';
	data.limit = 2;
	data.src_size = ft_lstsize(*a);
	data.dst_size = ft_lstsize(*b);
	fill(a, b, &data);
	data.limit = 0;
	data.stack_flag = 'b';
	data.src_size = ft_lstsize(*b);
	data.dst_size = ft_lstsize(*a);
	fill(b, a, &data);
	add_index(a);
	rotate_min_on_top(a);
}
