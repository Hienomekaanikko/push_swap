/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:58:08 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/17 18:14:53 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dst, const char *operation)
{
	t_stack	*temp;

	temp = *src;
	*src = (*src)->next;
	temp->next = (*dst);
	*dst = temp;
	if (ft_strncmp(operation, "pb", 2) == 0)
		ft_putendl_fd("pb", 1);
	else if (ft_strncmp(operation, "pa", 2) == 0)
		ft_putendl_fd("pa", 1);
}

void	rotate(t_stack **src, const char *operation)
{
	t_stack	*first;
	t_stack	*last;

	first = (*src);
	last = ft_lstlast(*src);
	*src = first->next;
	last->next = first;
	first->next = NULL;
	if (ft_strncmp(operation, "ra", 2) == 0)
		ft_putendl_fd("ra", 1);
	else if (ft_strncmp(operation, "rb", 2) == 0)
		ft_putendl_fd("rb", 1);
}

void	rot_both(t_stack **src, t_stack **dst, const char *op, t_data *data)
{
	rotate(src, "rr");
	rotate(dst, "rr");
	if (ft_strncmp(op, "rr", 2) == 0)
	{
		ft_putendl_fd("rr", 1);
		data->src_index--;
		data->dst_index--;
	}
}

void	reverse(t_stack **src, const char *operation)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*second_last;

	first = *src;
	second_last = *src;
	last = ft_lstlast(*src);
	while (second_last->next != last)
		second_last = second_last->next;
	*src = last;
	(*src)->next = first;
	second_last->next = NULL;
	if (ft_strncmp(operation, "rra", 3) == 0)
		ft_putendl_fd("rra", 1);
	else if (ft_strncmp(operation, "rrb", 3) == 0)
		ft_putendl_fd("rrb", 1);
}
