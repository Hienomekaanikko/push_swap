/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:14:37 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/28 12:31:01 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	cheapest_src(int cheapest, t_list **src, t_list **dest)
{
	t_list	*temp;

	temp = *src;
	add_index(src, dest);
	while (temp && temp->cost != cheapest)
		temp = temp->next;
	return (temp->index);
}

static int	cheapest_dst(int cheapest, t_list **src, t_list **dest)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = *src;
	temp_b = *dest;
	add_index(src, dest);
	while (temp_a && temp_a->cost != cheapest)
		temp_a = temp_a->next;
	while (temp_b && *(long long*)temp_b->content != temp_a->target)
		temp_b = temp_b->next;
	return(temp_b->index);
}

static void	position(t_list **stack_src, t_list **stack_dst, int cheapest, int size_src, int size_dst, int stack_flag)
{
	int	dst_index;
	int	src_index;
 	int	src_median;
	int	dst_median;

 	src_median = size_src / 2;
	dst_median = size_dst / 2;
	src_index = cheapest_src(cheapest, stack_src, stack_dst);
	dst_index = cheapest_dst(cheapest, stack_src, stack_dst);
	while (*(long long*)(*stack_dst)->content != (long long)(*stack_src)->target)
	{
		if (src_index == size_src)
			src_index = 0;
		if (dst_index == size_dst)
			dst_index = 0;
		if ((src_index > 0 && dst_index > 0) && (src_index <= src_median && dst_index <= dst_median))
		{
			rr(stack_src, stack_dst);
			src_index--;
			dst_index--;
		}
		else if ((src_index > src_median && dst_index > dst_median) && (src_index < size_src && dst_index < size_dst))
		{
			rrr(stack_src, stack_dst);
			src_index++;
			dst_index++;
		}
		else if (src_index == 0 && dst_index > 0 && dst_index <= dst_median)
		{
			if (stack_flag == 'a')
				rb(stack_dst);
			else
				ra(stack_dst);
			dst_index--;
		}
		else if (src_index == 0 && dst_index > 0 && dst_index > dst_median)
		{
			if (stack_flag == 'a')
				rrb(stack_dst);
			else
				rra(stack_dst);
			dst_index++;
		}
		else if (dst_index == 0 && src_index > 0 && src_index <= src_median)
		{
			if (stack_flag == 'a')
				ra(stack_src);
			else
				rb(stack_src);
			src_index--;
		}
		else if (dst_index == 0 && src_index > src_median)
		{
			if (stack_flag == 'a')
				rra(stack_src);
			else
				rrb(stack_src);
			src_index++;
		}
		else if (src_index == 0 && dst_index > dst_median)
		{
			if (stack_flag == 'a')
				rrb(stack_dst);
			else
				rra(stack_dst);
			dst_index++;
		}
		else if (dst_index == 0 && src_index > src_median && src_index < size_src)
		{
			if (stack_flag == 'a')
				rra(stack_src);
			else
				rrb(stack_src);
			src_index++;
		}
		else
		{
			if (stack_flag == 'a')
				ra(stack_src);
			else
				rb(stack_src);
			src_index--;
		}
	}
}

static int	find_cheapest(t_list **stack)
{
	t_list	*temp;
	int		cheapest;

	temp = *stack;
	cheapest = temp->cost;
	while (temp)
	{
		if (temp->cost == 0)
		{
			cheapest = 0;
			break ;
		}
		if (temp->cost < cheapest)
			cheapest = temp->cost;
		temp = temp->next;
	}
	return (cheapest);
}

static void min_max_check(t_list **stack, long long *min, long long *max)
{
	if (*(long long*)(*stack)->content > *max)
		*max = *(long long*)(*stack)->content;
	if (*(long long*)(*stack)->content < *min)
		*min = *(long long*)(*stack)->content;
}

static void	fill_b(t_list **stack_src, t_list **stack_dst, int *size_src, int *size_dst)
{
	int	cheapest;
	long long	min;
	long long	max;

	max = highest(stack_dst);
	min = lowest(stack_dst);
	while(*size_src > 2)
	{
		cheapest = find_cheapest(stack_src);
		position(stack_src, stack_dst, cheapest, *size_src, *size_dst, 'a');
		pb(stack_src, stack_dst);
		min_max_check(stack_dst, &min, &max);
		add_targets_a(stack_src, stack_dst);
		count_cost(stack_src, stack_dst, size_src, size_dst);
		(*size_src)--;
		(*size_dst)++;
	}
}
static void	fill_a(t_list **stack_src, t_list **stack_dst, int *size_src, int *size_dst)
{
	int	cheapest;
	long long	min;
	long long	max;

	max = highest(stack_src);
	min = lowest(stack_src);
	while (*size_dst > 0)
	{
		add_targets_b(stack_src, stack_dst);
		count_cost(stack_dst, stack_src, size_src, size_dst);
		cheapest = find_cheapest(stack_dst);
		position(stack_dst, stack_src, cheapest, *size_dst, *size_src, 'b');
		pa(stack_src, stack_dst);
		min_max_check(stack_src, &min, &max);
		(*size_src)++;
		(*size_dst)--;
	}
}

void	long_sort(t_list **stack_src, t_list **stack_dst, int *size_src, int *size_dst)
{
	t_list	*temp_a;

	temp_a = *stack_src;
	if (!temp_a)
		return ;
	fill_b(stack_src, stack_dst, size_src, size_dst);
	short_sort(stack_src);
	fill_a(stack_src, stack_dst, size_src, size_dst);
	rotate_min_on_top(stack_src);
}
