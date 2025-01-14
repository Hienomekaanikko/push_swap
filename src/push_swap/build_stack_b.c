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


static void	roll_position(t_list **stack_a, t_list **stack_b, int cheapest)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		a_median;
	int		b_median;
	int		a_size;
	int		b_size;
	int		i;
	int		j;

	a_size = ft_lstsize(*stack_a);
	b_size = ft_lstsize(*stack_b);
	a_median = a_size / 2;
	b_median = b_size / 2;
	temp_a = *stack_a;
	temp_b = *stack_b;
	i = 0;
	j = 0;
	while (temp_a->cost != cheapest)
	{
		temp_a = temp_a->next;
		i++;
	}
	while (*(int *)temp_b->content != temp_a->target)
	{
		temp_b = temp_b->next;
		j++;
	}
	while (i > 0 && j > 0 && i < a_size && j < b_size)
	{
		if (i >= a_median && j >= b_median)
		{
			rrr(stack_a, stack_b);
			i++;
			j++;
		}
		 if (i <= a_median && j <= b_median)
		{
			rr(stack_a, stack_b);
			i--;
			j--;
		}
	}
	if (i <= a_median)
	{
		while (i > 0)
		{
			ra(stack_a);
			i--;
		}
	}
	if (j <= b_median)
	{
		while (j > 0)
		{
			rb(stack_b);
			j--;
		}
	}
	if (i > a_median)
	{
		i = a_size - i;
		while (i--)
			rra(stack_a);
	}
	if (j > b_median)
	{
		j = b_size - j;
		while (j--)
			rrb(stack_b);
	}
	pb(stack_a, stack_b);
}

void	build_stack_b(t_list **stack_a, t_list **stack_b)
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
	roll_position(stack_a, stack_b, cheapest);
	add_targets(stack_a, stack_b);
	count_cost(stack_a, stack_b);
	build_stack_b(stack_a, stack_b);
	rotate_max_on_top(stack_b);
}
