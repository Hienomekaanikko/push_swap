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
	ft_printf("pb\n");
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
	ft_printf("pa\n");
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
	ft_printf("sa\n");
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
	ft_printf("sb\n");
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
	ft_printf("ra\n");
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
	ft_printf("rb\n");
}
void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
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
	ft_printf("rra\n");
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
	ft_printf("rrb\n");
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
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
