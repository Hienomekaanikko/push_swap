/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:58:08 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/31 12:41:44 by msuokas          ###   ########.fr       */
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

void	rotate_both(t_list **stack_src, t_list **stack_dst, const char *operation, t_data *data)
{
	rotate(stack_src, "rr");
	rotate(stack_dst, "rr");
	if (ft_strncmp(operation, "rr", 2) == 0)
	{
		ft_putendl_fd("rr", 1);
		data->src_index--;
		data->dst_index--;
	}
}
