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

static void	add_index(t_list **stack_src, t_list **stack_dst)
{
	t_list	*temp_src;
	t_list	*temp_dst;
	int		pos;

	temp_src = *stack_src;
	temp_dst = *stack_dst;
	pos = 0;
	while (temp_src)
	{
		temp_src->index = pos;
		pos++;
		temp_src = temp_src->next;
	}
	pos = 0;
	while (temp_dst)
	{
		temp_dst->index = pos;
		pos++;
		temp_dst = temp_dst->next;
	}
}

static void	count_cost(t_list **stack_src, t_list **stack_dst, t_data *data)
{
	t_list	*temp_src;
	t_list	*temp_dst;
	int		cost;
	int		dst_median;

	dst_median = data->dst_median;
	temp_src = *stack_src;
	add_index(stack_src, stack_dst);
	while(temp_src)
	{
		temp_dst = *stack_dst;
		cost = temp_src->index;
		while (temp_dst)
		{
			if (*temp_dst->content == temp_src->target)
				break ;
			else if (temp_dst->index <= dst_median)
				cost++;
			else if (temp_dst->index > dst_median)
				cost--;
			temp_dst = temp_dst->next;
		}
		temp_src->cost = cost;
		temp_src = temp_src->next;
	}
}

static void	update_best_target(t_list *temp_src, t_list *temp_dst, t_data *data, long long *temp)
{
	if (*temp_dst->content < *temp_src->content
		&& data->stack_flag == 'a' && *temp_dst->content > *temp)
		*temp = *temp_dst->content;
	else if (*temp_dst->content > *temp_src->content
		&& data->stack_flag == 'b' && *temp_dst->content < *temp)
		*temp = *temp_dst->content;
}

void	add_targets(t_list **stack_src, t_list **stack_dst, t_data *data)
{
	t_list		*temp_src;
	t_list		*temp_dst;
	long long	temp;

	temp_src = *stack_src;
	while (temp_src)
	{
		if (data->stack_flag == 'a')
			temp = data->lowest;
		else if (data->stack_flag == 'b')
			temp = data->highest;
		temp_dst = *stack_dst;
		while (temp_dst)
		{
			update_best_target(temp_src, temp_dst, data, &temp);
			temp_dst = temp_dst->next;
		}
		if (temp > *temp_src->content && data->stack_flag =='a')
			temp = data->highest;
		if (temp < *temp_src->content && data->stack_flag =='b')
			temp = data->lowest;
		temp_src->target = temp;
		temp_src = temp_src->next;
	}
	count_cost(stack_src, stack_dst, data);
}

