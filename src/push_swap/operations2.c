/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:07:24 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/10 09:57:58 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_both(t_list **src, t_list **dst, const char *op, t_data *data)
{
	reverse(src, "rrr");
	reverse(dst, "rrr");
	if (ft_strncmp(op, "rrr", 3) == 0)
	{
		ft_putendl_fd("rrr", 1);
		data->src_index++;
		data->dst_index++;
	}
}

void	free_stack(t_list **src)
{
	t_list	*tmp;

	if (!src || !(*src))
		return ;
	while (*src)
	{
		tmp = (*src)->next;
		free((*src)->content);
		free(*src);
		*src = tmp;
	}
	*src = NULL;
}

void	reverse(t_list **src, const char *operation)
{
	t_list	*first;
	t_list	*last;
	t_list	*second_last;

	if (*src == NULL || (*src)->next == NULL)
		return ;
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

int	find_cheapest(t_list **stack)
{
	t_list	*temp_stack;
	int		cheapest;

	temp_stack = *stack;
	cheapest = temp_stack->cost;
	while (temp_stack)
	{
		if (temp_stack->cost == 0)
		{
			cheapest = 0;
			break ;
		}
		if (temp_stack->cost < cheapest)
			cheapest = temp_stack->cost;
		temp_stack = temp_stack->next;
	}
	return (cheapest);
}
