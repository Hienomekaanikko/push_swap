/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:55:11 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/10 10:35:09 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_list **src, const char *operation)
{
	t_list	*first;
	t_list	*second;
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

void	three_num(t_list **a)
{
	t_list		*temp;
	long long	min;
	long long	max;

	temp = *a;
	min = lowest(a);
	max = highest(a);
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

void	short_sort(t_list **a)
{
	int		size;
	t_list	*temp;

	temp = *a;
	size = ft_lstsize(*a);
	if (size == 3)
		three_num(a);
	else if (size == 2)
	{
		if (*temp->content > *temp->next->content)
			s(a, "sa");
	}
}
