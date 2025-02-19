/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_prep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:16:04 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/17 18:17:59 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_index(t_stack **src)
{
	t_stack	*temp_src;
	int		pos;

	temp_src = *src;
	pos = 0;
	while (temp_src)
	{
		temp_src->index = pos;
		pos++;
		temp_src = temp_src->next;
	}
}

static int	src_dist(int cheapest, t_stack **src)
{
	t_stack	*temp_src;

	temp_src = *src;
	while (temp_src && temp_src->cost != cheapest)
		temp_src = temp_src->next;
	return (temp_src->index);
}

static int	dst_dist(int cheapest, t_stack **src, t_stack **dst)
{
	t_stack	*temp_src;
	t_stack	*temp_dst;

	temp_src = *src;
	temp_dst = *dst;
	while (temp_src && temp_src->cost != cheapest)
		temp_src = temp_src->next;
	while (temp_dst && *temp_dst->content != temp_src->target)
		temp_dst = temp_dst->next;
	return (temp_dst->index);
}

void	update_values(t_stack **src, t_stack **dst, t_data *data)
{
	data->highest = highest(dst);
	data->lowest = lowest(dst);
	add_index(src);
	add_index(dst);
	data->src_median = data->src_size / 2;
	data->dst_median = data->dst_size / 2;
	add_targets(src, dst, data);
	data->cheapest = find_cheapest(src);
	data->src_index = src_dist(data->cheapest, src);
	data->dst_index = dst_dist(data->cheapest, src, dst);
}
