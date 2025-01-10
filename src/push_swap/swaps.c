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
	int		moves;

	temp_a = *stack_a;
	moves = cheapest - 1;
	while (temp_a->cost != cheapest)
	{
		ra(stack_a);
		temp_a = temp_a->next;
		moves--;
	}
	while (moves > 0)
	{
		rb(stack_b);
		moves--;
	}
	pb(stack_a, stack_b);
}

void	find_cheapest(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	int		cheapest;

	temp_a = *stack_a;
	cheapest = temp_a->cost;
	if (temp_a ->next == NULL)
		return ;
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
	ft_printf("Least moves needed: %d \n", cheapest);
	roll_position(stack_a, stack_b, cheapest);
	add_targets(stack_a, stack_b);
	count_cost(stack_a, stack_b);
	find_cheapest(stack_a, stack_b);
}
