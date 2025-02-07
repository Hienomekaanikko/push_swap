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

int	dst_to_top_dist(int cheapest, t_list **src, t_list **dst)
{
	t_list	*temp_src;
	t_list	*temp_dst;

	temp_src = *src;
	temp_dst = *dst;
	while (temp_src && temp_src->cost != cheapest)
		temp_src = temp_src->next;
	while (temp_dst && *temp_dst->content != temp_src->target)
		temp_dst = temp_dst->next;
	return(temp_dst->index);
}
