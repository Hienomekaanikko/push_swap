/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:55:11 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/17 18:30:32 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack **src, const char *operation)
{
	t_stack	*first;
	t_stack	*second;
	int		len;

	if (!src)
		return ;
	len = ft_lstsize(*src);
	if (len < 2)
		return ;
	first = (*src);
	second = (*src)->next;
	first->next = second->next;
	second->next = first;
	*src = second;
	if (ft_strncmp(operation, "sa", 2) == 0)
		ft_putendl_fd("sa", 1);
	else if (ft_strncmp(operation, "rb", 2) == 0)
		ft_putendl_fd("sb", 1);
}

static void	three_num(t_stack **a, long long min, long long max)
{
	t_stack		*temp;

	if (!a || !(*a))
		return ;
	temp = *a;
	if (*temp->content == min && *temp->next->content != max)
		return ;
	else if (*temp->content == min && *temp->next->content == max)
	{
		reverse(a, "rra");
		s(a, "sa");
	}
	else if (*temp->content != min && *temp->next->content == max)
		reverse(a, "rra");
	else if (*temp->content == max && *temp->next->content == min)
		rotate(a, "ra");
	else if (*temp->content == max && *temp->next->content != min)
	{
		s(a, "sa");
		reverse(a, "rra");
	}
	else if (*temp->content != min && *temp->next->content != max)
		s(a, "sa");
}

void	sort_short(t_stack **a, size_t size)
{
	long long	min;
	long long	max;
	t_stack		*temp;

	temp = *a;
	if (size == 3)
	{
		min = lowest(a);
		max = highest(a);
		three_num(a, min, max);
	}
	else if (size == 2)
	{
		if (*temp->content > *temp->next->content)
			s(a, "sa");
	}
}
