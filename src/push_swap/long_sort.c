/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:14:37 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/10 18:22:35 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	a_cheapest_index(int cheapest, t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;

	temp_a = *stack_a;
	add_index(stack_a, stack_b);
	while (temp_a->cost != cheapest)
		temp_a = temp_a->next;
	return (temp_a->index);
}

static int	b_cheapest_index(int cheapest, t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;
	t_list	*temp_a;

	temp_b = *stack_b;
	temp_a = *stack_a;
	add_index(stack_a, stack_b);
	while (temp_a->cost != cheapest)
		temp_a = temp_a->next;
	while (*(int*)temp_b->content != temp_a->target)
		temp_b = temp_b->next;
	return(temp_b->index);
}

static void	swaps(t_list **stack_a, t_list **stack_b, int cheapest)
{
	int	b_index;
	int	a_index;
 	int	a_size;
	int	b_size;
 	int	a_median;
	int	b_median;

	a_size = ft_lstsize(*stack_a);
	b_size = ft_lstsize(*stack_b);
 	a_median = a_size / 2;
	b_median = b_size / 2;
	while (*(int*)(*stack_b)->content != (*stack_a)->target)
	{
		a_index = a_cheapest_index(cheapest, stack_a, stack_b);
		b_index = b_cheapest_index (cheapest, stack_a, stack_b);
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
	pb(stack_a, stack_b);
}

void	long_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	int		cheapest;
	temp_a = *stack_a;
	if (temp_a == NULL)
		return ;
	cheapest = temp_a->cost;
	while (temp_a)
	{
		if (temp_a->cost == 0)
		{
			cheapest = 0;
			break ;
		}
		if (temp_a->cost < cheapest)
			cheapest = temp_a->cost;
		temp_a = temp_a->next;
	}
	swaps(stack_a, stack_b, cheapest);
	add_targets(stack_a, stack_b);
	count_cost(stack_a, stack_b);
	long_sort(stack_a, stack_b);
	rotate_max_on_top(stack_b);
}
