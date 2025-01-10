/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:14:37 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/10 16:26:17 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//now when we have the costs, swap according to it. use indexes as help.
//for example if cost is 8 and stack_a is already at index 0, the moves are in the stack b.
//if cost is 8 and stack_a is at index 4, then it'll move up until in zero and then moves stack_b.
//(or actually at that case both can be moved at the same time.)

#include "push_swap.h"

// static void	move(t_list **stack_a, t_list **stack_b, int cheapest)
// {
// 	t_list	*temp_a;
// 	t_list	*temp_b;

// 	temp_a = stack_a;
// 	temp_b = stack_b;
// 	int	moves;
// 	moves = cheapest;
// 	while (temp_a->cost != cheapest)
// 	{
// 		ra(temp_a);
// 		moves--;
// 	}
// 	while (moves > 0)
// 	{
// 		rb(temp_b);
// 		moves--;
// 	}
// }

void	find_cheapest(t_list **stack_a)
{
	t_list	*temp_a;
	int		cheapest;

	temp_a = *stack_a;
	cheapest = temp_a->cost;
	if (temp_a->next == NULL)
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
	temp_a = *stack_a;
	ft_printf("Least moves needed: %d ", cheapest);
}
