/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:48:55 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/31 15:05:27 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_index(t_list **src)
{
	t_list	*temp_src;
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

static void	count_cost(t_list **src, t_list **dst, t_data *data)
{
	t_list	*temp_src;
	t_list	*temp_dst;
	int		cost_src;
	int		cost_dst;

	temp_src = *src;
	add_index(src);
	add_index(dst);
	while(temp_src)
	{
		cost_dst = 0;
		temp_dst = *dst;
		cost_src = temp_src->index;
		if (cost_src > data->src_median)
			cost_src = data->src_size - cost_src;
		while (*temp_dst->content != temp_src->target)
		{
			cost_dst++;
			temp_dst = temp_dst->next;
		}
		if (cost_dst > data->dst_median)
			cost_dst = data->dst_size - cost_dst;
		temp_src->cost = cost_src + cost_dst;
		temp_src = temp_src->next;
	}
}

static void	update_target(t_list *src, t_list *dst, t_data *data, long long *temp)
{
	if (*dst->content < *src->content
		&& data->stack == 'a' && *dst->content > *temp)
		*temp = *dst->content;
	else if (*dst->content > *src->content
		&& data->stack == 'b' && *dst->content < *temp)
		*temp = *dst->content;
}

void	add_targets(t_list **src, t_list **dst, t_data *data)
{
	t_list		*temp_src;
	t_list		*temp_dst;
	long long	temp;

	temp_src = *src;
	while (temp_src)
	{
		if (data->stack == 'a')
			temp = data->lowest;
		else if (data->stack == 'b')
			temp = data->highest;
		temp_dst = *dst;
		while (temp_dst)
		{
			update_target(temp_src, temp_dst, data, &temp);
			temp_dst = temp_dst->next;
		}
		if (temp > *temp_src->content && data->stack =='a')
			temp = data->highest;
		if (temp < *temp_src->content && data->stack =='b')
			temp = data->lowest;
		temp_src->target = temp;
		temp_src = temp_src->next;
	}
	count_cost(src, dst, data);
}

