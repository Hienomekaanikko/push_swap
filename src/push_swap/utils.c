/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:19:31 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/14 16:19:29 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *msg, char **args, int should_free)
{
	if (should_free)
		ft_free_split(args);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	init_data_a(t_stack **a, t_stack **b, t_data *data)
{
	data->limit = 2;
	data->stack_flag = 'a';
	data->src_size = ft_lstsize(*a);
	data->dst_size = ft_lstsize(*b);
	data->highest = highest(b);
	data->lowest = lowest(b);
}

void	init_data_b(t_stack **a, t_stack **b, t_data *data)
{
	data->limit = 0;
	data->stack_flag = 'b';
	data->src_size = ft_lstsize(*b);
	data->dst_size = ft_lstsize(*a);
	data->highest = highest(a);
	data->lowest = lowest(a);
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
