/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_prep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:16:04 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/31 15:11:05 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	src_to_top_dist(int cheapest, t_list **src)
{
	t_list	*temp_src;

	temp_src = *src;
	while (temp_src && temp_src->cost != cheapest)
		temp_src = temp_src->next;
	return (temp_src->index);
}

int	dst_to_top_dist(int cheapest, t_list **src, t_list **dest)
{
	t_list	*temp_src;
	t_list	*temp_dst;

	temp_src = *src;
	temp_dst = *dest;
	while (temp_src && temp_src->cost != cheapest)
		temp_src = temp_src->next;
	while (temp_dst && *temp_dst->content != temp_src->target)
		temp_dst = temp_dst->next;
	return(temp_dst->index);
}

void	other_case(t_list **stack_src, t_data *data)
{
	if (data->stack_flag == 'a')
		rotate(stack_src, "ra");
	else
		rotate(stack_src, "rb");
	data->src_index--;
}
