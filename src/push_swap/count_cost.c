/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:48:55 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/10 10:06:42 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_index(t_list **src)
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
	int		cost;
	int		cost_b;

	temp_src = *src;
	while (temp_src)
	{
		cost_b = 0;
		temp_dst = *dst;
		cost = temp_src->index;
		if (cost >= data->src_median)
			cost = data->src_size - cost;
		while (temp_dst)
		{
			if (*temp_dst->content == temp_src->target)
				break ;
			cost_b++;
			temp_dst = temp_dst->next;
		}
		if (cost_b >= data->dst_median)
			cost_b = data->dst_size - cost_b;
		temp_src->cost = cost + cost_b;
		temp_src = temp_src->next;
	}
}

static void	target(t_list *src, t_list *dst, t_data *data, long long *temp)
{
	if (*dst->content < *src->content
		&& data->stack_flag == 'a' && *dst->content > *temp)
		*temp = *dst->content;
	else if (*dst->content > *src->content
		&& data->stack_flag == 'b' && *dst->content < *temp)
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
		if (data->stack_flag == 'a')
			temp = data->lowest;
		else if (data->stack_flag == 'b')
			temp = data->highest;
		temp_dst = *dst;
		while (temp_dst)
		{
			target(temp_src, temp_dst, data, &temp);
			temp_dst = temp_dst->next;
		}
		if (temp > *temp_src->content && data->stack_flag == 'a')
			temp = data->highest;
		if (temp < *temp_src->content && data->stack_flag == 'b')
			temp = data->lowest;
		temp_src->target = temp;
		temp_src = temp_src->next;
	}
	count_cost(src, dst, data);
}
