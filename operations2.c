/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:07:24 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/17 18:12:22 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_both(t_stack **src, t_stack **dst, const char *op, t_data *data)
{
	reverse(src, "rrr");
	reverse(dst, "rrr");
	if (ft_strncmp(op, "rrr", 3) == 0)
	{
		ft_putendl_fd("rrr", 1);
		data->src_index++;
		data->dst_index++;
	}
}

void	rotate_min_on_top(t_stack **stack)
{
	t_stack		*temp;
	int			size;
	int			median;
	int			i;
	long long	target;

	size = ft_lstsize(*stack);
	median = (size + 1) / 2;
	target = lowest(stack);
	temp = *stack;
	while (*temp->content != target)
		temp = temp->next;
	i = temp->index;
	if (i < median)
	{
		while (*(*stack)->content != target)
			rotate(stack, "ra");
	}
	else
	{
		while (*(*stack)->content != target)
			reverse(stack, "rra");
	}
}
