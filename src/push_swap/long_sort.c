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
#include <stdio.h>

static void	position(t_list **src, t_list **dst, t_data *data)
{
	int	dst_steps;
	int src_steps;
	int dst_size;
	int src_size;

	while (*(*dst)->content != (*src)->target)
	{
		dst_steps = data->dst_index;
		src_steps = data->src_index;
		dst_size = data->dst_size;
		src_size = data->src_size;
		if ((src_steps > 0 && dst_steps > 0)
			&& (src_steps <= data->src_median && dst_steps <= data->dst_median))
			rotate_both(src, dst, "rr", data);
		else if ((src_steps > data->src_median && dst_steps > data->dst_median)
			&& (src_steps < src_size && dst_steps < dst_size))
			reverse_both(src, dst, "rrr", data);
		else if (src_steps >= 0 && dst_steps > 0)
			rotate_dst(dst, data);
		else if (dst_steps >= 0 && src_steps > 0)
			rotate_src(src, data);
		else if (src_steps >= 0 && dst_steps > data->dst_median)
			reverse_dst(dst, data);
		else if (dst_steps >= 0 && src_steps > data->src_median)
			reverse_src(src, data);
	}
}

static void	fill(t_list **src, t_list **dst, t_data *data)
{
	while(data->src_size > data->leftover)
	{
		data->highest = highest(dst);
		data->lowest = lowest(dst);
		add_targets(src, dst, data);
		data->cheapest = find_cheapest(src);
		data->src_median = (data->src_size + 1) / 2;
		data->dst_median = (data->dst_size + 1) / 2;
		data->src_index = src_to_top_dist(data->cheapest, src);
		data->dst_index = dst_to_top_dist(data->cheapest, src, dst);
		if (data->src_index == 0 && data->dst_index == 0 && data->stack == 'a')
			push(src, dst, "pb");
		else if (data->src_index == 0 && data->dst_index == 0 && data->stack == 'b')
			push(src, dst, "pa");
		else
		{
			position(src, dst, data);
			if (data->stack == 'a')
				push(src, dst, "pb");
			else
				push(src, dst, "pa");
		}
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
	data.stack = 'a';
	data.leftover = 2;
	data.src_size = ft_lstsize(*a);
	data.dst_size = ft_lstsize(*b);
	fill(a, b, &data);
	data.leftover = 0;
	data.stack = 'b';
	data.src_size = ft_lstsize(*b);
	data.dst_size = ft_lstsize(*a);
	fill(b, a, &data);
	rotate_min_on_top(a);
}
