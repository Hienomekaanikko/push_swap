/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:58:08 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/17 13:09:38 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first_two(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	int		len;

	if (!stack)
		return ;
	len = ft_lstsize(*stack);
	if (len < 2)
		return ;
	first = (*stack);
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ft_putendl_fd("sa", 2);
}

void	rotate_one_up(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = (*stack);
	last = ft_lstlast(*stack);
	*stack = first->next;
	last->next = first;
	first->next = NULL;
	//print ra or rb
}

void	reverse_rotate_one(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second_last = *stack;
	last = ft_lstlast(*stack);
	while (second_last->next != last)
		second_last = second_last->next;
	*stack = last;
	(*stack)->next = first;
	second_last->next = NULL;
}

void	rotate_max_on_top(t_list **stack)
{
	long		target;

	target = highest(stack);
	while (*(long long*)(*stack)->content != target)
	{
		rotate_one_up(stack);
		ft_putendl_fd("rb", 1);
	}
}

void	rotate_min_on_top(t_list **stack)
{
	long		target;

	target = lowest(stack);
	while (*(long long*)(*stack)->content != target)
	{
		rotate_one_up(stack);
		ft_putendl_fd("ra", 1);
	}
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
