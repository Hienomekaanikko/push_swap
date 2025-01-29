/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:58:08 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/29 12:32:51 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_src, t_list **stack_dst, const char *operation)
{
	t_list	*temp;

	if (*stack_src == NULL)
		return ;
	temp = *stack_src;
	*stack_src = (*stack_src)->next;
	temp->next = (*stack_dst);
	*stack_dst = temp;
	if (ft_strncmp(operation, "pb", 2) == 0)
		ft_putendl_fd("pb", 1);
	else if (ft_strncmp(operation, "pa", 2) == 0)
		ft_putendl_fd("pa", 1);
}

void	s(t_list **stack_src, const char *operation)
{
	t_list	*first;
	t_list	*second;
	int		len;

	if (!stack_src)
		return ;
	len = ft_lstsize(*stack_src);
	if (len < 2)
		return ;
	first = (*stack_src);
	second = (*stack_src)->next;
	first->next = second->next;
	second->next = first;
	*stack_src = second;
	if (ft_strncmp(operation, "sa", 2) == 0)
		ft_putendl_fd("sa", 1);
	else if (ft_strncmp(operation, "rb", 2) == 0)
		ft_putendl_fd("sb", 1);
}

void	rotate(t_list **stack_src, const char *operation)
{
	t_list	*first;
	t_list	*last;

	if (*stack_src == NULL || (*stack_src)->next == NULL)
		return ;
	first = (*stack_src);
	last = ft_lstlast(*stack_src);
	*stack_src = first->next;
	last->next = first;
	first->next = NULL;
	if (ft_strncmp(operation, "ra", 2) == 0)
		ft_putendl_fd("ra", 1);
	else if (ft_strncmp(operation, "rb", 2) == 0)
		ft_putendl_fd("rb", 1);
}

void	rotate_both(t_list **stack_src, t_list **stack_dst, const char *operation)
{
	rotate(stack_src, "rr");
	rotate(stack_dst, "rr");
	if (ft_strncmp(operation, "rr", 2) == 0)
		ft_putendl_fd("rr", 1);
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

void reverse_both(t_list **stack_src, t_list **stack_dst, const char *operation)
{
	reverse(stack_src, "rrr");
	reverse(stack_dst, "rrr");
	if (ft_strncmp(operation, "rrr", 3) == 0)
		ft_putendl_fd("rrr", 1);
}

void	rotate_max_on_top(t_list **stack_src)
{
	long long	target;

	target = highest(stack_src);
	while (*(long long *)(*stack_src)->content != target)
		rotate(stack_src, "rb");
}

void	rotate_min_on_top(t_list **stack_src)
{
	long long	target;

	target = lowest(stack_src);
	while (*(long long *)(*stack_src)->content != target)
		rotate(stack_src, "ra");
}

void	empty_b_to_a(t_list	**stack_src, t_list **stack_dst)
{
	int	size;

	size = ft_lstsize(*stack_dst);
	while (size > 0)
	{
		push(stack_dst, stack_src, "pa");
		size--;
	}
}
void	free_stack(t_list **stack_src)
{
	t_list	*tmp;

	if (!stack_src || !(*stack_src))
		return ;
	while (*stack_src)
	{
		tmp = (*stack_src)->next;
		free(*stack_src);
		*stack_src = tmp;
	}
	*stack_src = NULL;
}
