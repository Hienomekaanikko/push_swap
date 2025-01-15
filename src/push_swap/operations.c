/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:58:08 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/10 17:24:09 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_b);
	*stack_b = temp;
	ft_putendl_fd("pb", 1);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_a);
	*stack_a = temp;
	ft_putendl_fd("pa", 1);
}

void	sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;
	int		len;

	if (!stack_a)
		return ;
	len = ft_lstsize(*stack_a);
	if (len < 2)
		return ;
	first = (*stack_a);
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	ft_putendl_fd("sa", 1);
}

void	sb(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;
	int		len;

	if (!stack_b)
		return ;
	len = ft_lstsize(*stack_b);
	if (len < 2)
		return ;
	first = (*stack_b);
	second = (*stack_b)->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	ft_putendl_fd("sb", 1);
}

void	ra(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = (*stack_a);
	last = ft_lstlast(*stack_a);
	*stack_a = first->next;
	last->next = first;
	first->next = NULL;
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = (*stack_b);
	last = ft_lstlast(*stack_b);
	*stack_b = first->next;
	last->next = first;
	first->next = NULL;
	ft_putendl_fd("rb", 1);
}
void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_putendl_fd("rr", 1);
}

void	rra(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;
	t_list	*second_last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second_last = *stack_a;
	last = ft_lstlast(*stack_a);
	while (second_last->next != last)
		second_last = second_last->next;
	*stack_a = last;
	(*stack_a)->next = first;
	second_last->next = NULL;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;
	t_list	*second_last;

	first = *stack_b;
	second_last = *stack_b;
	last = ft_lstlast(*stack_b);
	while (second_last->next != last)
		second_last = second_last->next;
	*stack_b = last;
	(*stack_b)->next = first;
	second_last->next = NULL;
	ft_putendl_fd("rrb", 1);
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*last_a;
	t_list	*second_last_a;
	t_list	*last_b;
	t_list	*second_last_b;

	if (*stack_a && (*stack_a)->next)
	{
		second_last_a = *stack_a;
		while (second_last_a->next->next)
			second_last_a = second_last_a->next;
		last_a = second_last_a->next;
		second_last_a->next = NULL;
		last_a->next = *stack_a;
		*stack_a = last_a;
	}

	if (*stack_b && (*stack_b)->next)
	{
		second_last_b = *stack_b;
		while (second_last_b->next->next)
			second_last_b = second_last_b->next;
		last_b = second_last_b->next;
		second_last_b->next = NULL;
		last_b->next = *stack_b;
		*stack_b = last_b;
	}
	ft_putendl_fd("rrr", 1);
}

void	rotate_max_on_top(t_list **stack)
{
	int		target;

	target = highest(stack);
	while (*(int *)(*stack)->content != target)
	{
		rb(stack);
	}
}

void	empty_b_to_a(t_list	**stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_b);
	while (size > 0)
	{
		pa(stack_a, stack_b);
		size--;
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
