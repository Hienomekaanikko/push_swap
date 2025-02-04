/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:55:11 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/03 10:48:05 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	three_num(t_list **stack_a)
{
	t_list		*temp;
	long long	min;
	long long	max;

	temp = *stack_a;
	min = lowest(stack_a);
	max = highest(stack_a);
	if (*temp->content == min && *temp->next->content != max)
		return ;
	else if (*temp->content == min && *temp->next->content == max)
	{
		reverse(stack_a, "rra");
		s(stack_a, "sa");
	}
	else if (*temp->content != min && *temp->next->content == max)
		reverse(stack_a, "rra");
	else if (*temp->content == max && *temp->next->content == min)
		rotate(stack_a, "ra");
	else if (*temp->content == max && *temp->next->content != min)
	{
		s(stack_a, "sa");
		reverse(stack_a, "rra");
	}
	else if (*temp->content != min && *temp->next->content != max)
		s(stack_a, "sa");
}


void	short_sort(t_list **stack_a)
{
	int		size;
	t_list	*temp;

	temp = *stack_a;
	size = ft_lstsize(*stack_a);
	if (size == 3)
		three_num(stack_a);
	else if (size == 2)
	{
		if (*temp->content > *temp->next->content)
			s(stack_a, "sa");
	}
}
