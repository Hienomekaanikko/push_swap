/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:58:08 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/14 16:18:10 by msuokas          ###   ########.fr       */
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

void	add_index(t_stack **src)
{
	t_stack	*temp_src;
	int		pos;

	temp_src = *src;
	pos = 0;
	while (temp_src)
	{
		temp_src->index = pos;
		pos++;
		temp_src = temp_src->next;
	}
}
