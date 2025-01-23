/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:14:37 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/23 10:22:58 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cheapest_src(int cheapest, t_list **src, t_list **dest)
{
	t_list	*temp;

	temp = *src;
	add_index(src, dest);
	while (temp->cost != cheapest)
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
	while (temp_a->cost != cheapest)
		temp_a = temp_a->next;
	while (*(long long*)temp_b->content != temp_a->target)
		temp_b = temp_b->next;
	return(temp_b->index);
}

static void	position_for_b(t_list **stack_a, t_list **stack_b, int cheapest, int size_a, int size_b)
{
	int	b_index;
	int	a_index;
 	int	a_median;
	int	b_median;

 	a_median = size_a / 2;
	b_median = size_b / 2;
	while (*(long long*)(*stack_b)->content != (*stack_a)->target)
	{
		a_index = cheapest_src(cheapest, stack_a, stack_b);
		b_index = cheapest_dst(cheapest, stack_a, stack_b);
		if (a_index > 0 && b_index > 0 && a_index <= a_median && b_index <= b_median)
			rr(stack_a, stack_b);
		else if (a_index > a_median && a_index != 0 && b_index > b_median && b_index != 0)
			rrr(stack_a, stack_b);
		else if (a_index == 0 && b_index > 0 && b_index <= b_median)
			rb(stack_b);
		else if (b_index == 0 && a_index > 0 && a_index <= a_median)
			ra(stack_a);
		else if ((a_index == 0 || a_index < a_median) && b_index > b_median)
			rrb(stack_b);
		else if ((b_index == 0 || b_index < b_median) && a_index > a_median)
			rra(stack_a);
	}
}
static void	position_for_a(t_list **stack_a, t_list **stack_b, int cheapest, int size_a, int size_b)
{
	int	b_index;
	int	a_index;
 	int	a_median;
	int	b_median;

 	a_median = size_a / 2;
	b_median = size_b / 2;
	while (*(long long*)(*stack_a)->content != (*stack_b)->target)
	{

		b_index = cheapest_src(cheapest, stack_b, stack_a);
		a_index = cheapest_dst(cheapest, stack_b, stack_a);
		if (b_index > 0 && a_index > 0 && b_index <= b_median && a_index <= a_median)
			rr(stack_a, stack_b);
		else if (b_index > b_median && b_index != 0 && a_index > a_median && a_index != 0)
			rrr(stack_a, stack_b);
		else if (b_index == 0 && a_index > 0)
			ra(stack_a);
		else if (a_index == 0 && b_index > 0)
			rb(stack_a);
		else if (b_index == 0 && a_index > 0 && a_index <= a_median)
			ra(stack_a);
		else if (a_index == 0 && b_index > 0 && b_index <= b_median)
			rb(stack_b);
		else if ((b_index == 0 || b_index < b_median) && a_index > a_median)
			rra(stack_a);
		else if ((a_index == 0 || a_index < a_median) && b_index > b_median)
			rrb(stack_b);
	}
}

static int		find_cheapest(t_list **stack)
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

static void	fill_b(t_list **stack_a, t_list **stack_b, int *size_a, int *size_b)
{
	int	cheapest;
	long long	min;
	long long	max;

	max = highest(stack_b);
	min = lowest(stack_b);
	while(*size_a > 2)
	{
		cheapest = find_cheapest(stack_a);
		position_for_b(stack_a, stack_b, cheapest, *size_a, *size_b);
		pb(stack_a, stack_b);
		min_max_check(stack_b, &min, &max);
		add_targets_a(stack_a, stack_b, min, max);
		count_cost(stack_a, stack_b, size_a, size_b);
		(*size_a)--;
		(*size_b)++;
	}
}
static void	fill_a(t_list **stack_a, t_list **stack_b, int *size_a, int *size_b)
{
	int	cheapest;
	long long	min;
	long long	max;

	max = highest(stack_a);
	min = lowest(stack_a);
	while (*size_b > 0)
	{
		add_targets_b(stack_a, stack_b);
		count_cost_b(stack_a, stack_b, size_a, size_b);
		cheapest = find_cheapest(stack_b);
		position_for_a(stack_a, stack_b, cheapest, *size_a, *size_b);
		pa(stack_a, stack_b);
		min_max_check(stack_a, &min, &max);
		(*size_a)++;
		(*size_b)--;
	}
}

void	long_sort(t_list **stack_a, t_list **stack_b, int *size_a, int *size_b)
{
	t_list	*temp_a;

	temp_a = *stack_a;
	if (!temp_a)
		return ;
	fill_b(stack_a, stack_b, size_a, size_b);
	short_sort(stack_a);
	fill_a(stack_a, stack_b, size_a, size_b);
	rotate_min_on_top(stack_a);
}
