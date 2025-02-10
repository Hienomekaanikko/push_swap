/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:58:08 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/10 08:57:14 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **src, t_list **dst, const char *operation)
{
	t_list	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = (*dst);
	*dst = temp;
	if (ft_strncmp(operation, "pb", 2) == 0)
		ft_putendl_fd("pb", 1);
	else if (ft_strncmp(operation, "pa", 2) == 0)
		ft_putendl_fd("pa", 1);
}

void	rotate(t_list **src, const char *operation)
{
	t_list	*first;
	t_list	*last;

	if (*src == NULL || (*src)->next == NULL)
		return ;
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

void	rot_both(t_list **src, t_list **dst, const char *op, t_data *data)
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
