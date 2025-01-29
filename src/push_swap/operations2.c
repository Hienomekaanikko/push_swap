/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:07:24 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/29 16:54:06 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_both(t_list **stack_src, t_list **stack_dst, const char *operation)
{
	reverse(stack_src, "rrr");
	reverse(stack_dst, "rrr");
	if (ft_strncmp(operation, "rrr", 3) == 0)
		ft_putendl_fd("rrr", 1);
}

void free_stack(t_list **stack_src)
{
	t_list *tmp;

	if (!stack_src || !(*stack_src))
		return ;
	while (*stack_src)
	{
		tmp = (*stack_src)->next;
		free((*stack_src)->content);
		free(*stack_src);
		*stack_src = tmp;
	}
	*stack_src = NULL;
}

void	reverse(t_list **stack_src, const char *operation)
{
	t_list	*first;
	t_list	*last;
	t_list	*second_last;

	if (*stack_src == NULL || (*stack_src)->next == NULL)
		return ;
	first = *stack_src;
	second_last = *stack_src;
	last = ft_lstlast(*stack_src);
	while (second_last->next != last)
		second_last = second_last->next;
	*stack_src = last;
	(*stack_src)->next = first;
	second_last->next = NULL;
	if (ft_strncmp(operation, "rra", 3) == 0)
		ft_putendl_fd("rra", 1);
	else if (ft_strncmp(operation, "rrb", 3) == 0)
		ft_putendl_fd("rrb", 1);
}
int	find_cheapest(t_list **stack)
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
