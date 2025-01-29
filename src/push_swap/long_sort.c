/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:14:37 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/29 14:19:12 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	src_to_top_dist(int cheapest, t_list **src, t_list **dest)
{
	t_list	*temp_src;

	temp_src = *src;
	add_index(src, dest);
	while (temp_src && temp_src->cost != cheapest)
		temp_src = temp_src->next;
	return (temp_src->index);
}

static int	dst_to_top_dist(int cheapest, t_list **src, t_list **dest)
{
	t_list	*temp_src;
	t_list	*temp_dst;

	temp_src = *src;
	temp_dst = *dest;
	add_index(src, dest);
	while (temp_src && temp_src->cost != cheapest)
		temp_src = temp_src->next;
	while (temp_dst && *(long long*)temp_dst->content != temp_src->target)
		temp_dst = temp_dst->next;
	return(temp_dst->index);
}

static void	position(t_list **stack_src, t_list **stack_dst, int cheapest, int size_src, int size_dst, int stack_flag)
{
	int	dst_index;
	int	src_index;
 	int	src_median;
	int	dst_median;

 	src_median = size_src / 2;
	dst_median = size_dst / 2;
	src_index = src_to_top_dist(cheapest, stack_src, stack_dst);
	dst_index = dst_to_top_dist(cheapest, stack_src, stack_dst);
	while (*(long long*)(*stack_dst)->content != (long long)(*stack_src)->target)
	{
		if (src_index == size_src)
			src_index = 0;
		if (dst_index == size_dst)
			dst_index = 0;
		if ((src_index > 0 && dst_index > 0) && (src_index <= src_median && dst_index <= dst_median))
		{
			rotate_both(stack_src, stack_dst, "rr");
			src_index--;
			dst_index--;
		}
		else if ((src_index > src_median && dst_index > dst_median) && (src_index < size_src && dst_index < size_dst))
		{
			reverse_both(stack_src, stack_dst, "rrr");
			src_index++;
			dst_index++;
		}
		else if (src_index == 0 && dst_index > 0 && dst_index <= dst_median)
		{
			if (stack_flag == 'a')
				rotate(stack_dst, "rb");
			else
				rotate(stack_dst, "ra");
			dst_index--;
		}
		else if (src_index == 0 && dst_index > 0 && dst_index > dst_median)
		{
			if (stack_flag == 'a')
				reverse(stack_dst, "rrb");
			else
				reverse(stack_dst, "rra");
			dst_index++;
		}
		else if (dst_index == 0 && src_index > 0 && src_index <= src_median)
		{
			if (stack_flag == 'a')
				rotate(stack_src, "ra");
			else
				rotate(stack_src, "rb");
			src_index--;
		}
		else if (dst_index == 0 && src_index > src_median)
		{
			if (stack_flag == 'a')
				reverse(stack_src, "rra");
			else
				reverse(stack_src, "rrb");
			src_index++;
		}
		else if (src_index == 0 && dst_index > dst_median)
		{
			if (stack_flag == 'a')
				reverse(stack_dst, "rrb");
			else
				reverse(stack_dst, "rra");
			dst_index++;
		}
		else if (dst_index == 0 && src_index > src_median && src_index < size_src)
		{
			if (stack_flag == 'a')
				reverse(stack_src, "rra");
			else
				reverse(stack_src, "rrb");
			src_index++;
		}
		else
		{
			if (stack_flag == 'a')
				rotate(stack_src, "ra");
			else
				rotate(stack_src, "rb");
			src_index--;
		}
	}
}

static int	find_cheapest(t_list **stack)
{
	t_list	*temp_src;
	int		cheapest;

	temp_src = *stack;
	cheapest = temp_src->cost;
	while (temp_src)
	{
		if (temp_src->cost == 0)
		{
			cheapest = 0;
			break ;
		}
		if (temp_src->cost < cheapest)
			cheapest = temp_src->cost;
		temp_src = temp_src->next;
	}
	return (cheapest);
}

static void	fill_b(t_list **stack_src, t_list **stack_dst, int *size_src, int *size_dst)
{
	int	cheapest;
	while(*size_src > 2)
	{
		add_targets_a(stack_src, stack_dst, 'a');
		count_cost(stack_src, stack_dst);
		cheapest = find_cheapest(stack_src);
		position(stack_src, stack_dst, cheapest, *size_src, *size_dst, 'a');
		push(stack_src, stack_dst, "pb");
		(*size_src)--;
		(*size_dst)++;
	}
}
static void	fill_a(t_list **stack_src, t_list **stack_dst, int *size_src, int *size_dst)
{
	int	cheapest;
	while (*size_dst > 0)
	{
		add_targets_a(stack_dst, stack_src, 'b');
		count_cost(stack_dst, stack_src);
		cheapest = find_cheapest(stack_dst);
		position(stack_dst, stack_src, cheapest, *size_dst, *size_src, 'b');
		push(stack_dst, stack_src, "pa");
		(*size_src)++;
		(*size_dst)--;
	}
}

void	long_sort(t_list **stack_src, t_list **stack_dst, int *size_src, int *size_dst)
{
	t_list	*temp_src;

	temp_src = *stack_src;
	if (!temp_src)
		return ;
	fill_b(stack_src, stack_dst, size_src, size_dst);
	short_sort(stack_src);
	fill_a(stack_src, stack_dst, size_src, size_dst);
	rotate_min_on_top(stack_src);
}
