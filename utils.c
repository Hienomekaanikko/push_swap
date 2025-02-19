/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:19:31 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/17 18:21:15 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_stack **src, t_stack **dst)
{
	free_stack(src);
	free_stack(dst);
	exit(1);
}

void	free_stack(t_stack **src)
{
	t_stack	*tmp;

	while (*src)
	{
		tmp = (*src)->next;
		free((*src)->content);
		free(*src);
		*src = tmp;
	}
	*src = NULL;
}

void	error(char *msg, char **args, int should_free)
{
	if (should_free)
		ft_free_split(args);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	ft_add_node(t_stack **stack, long long content)
{
	t_stack		*new_node;
	t_stack		*temp;
	long long	*content_copy;

	if (!stack)
		return ;
	content_copy = malloc(sizeof(long long));
	if (!content_copy)
		return ;
	*content_copy = content;
	new_node = ft_lstnew(content_copy);
	if (!new_node)
	{
		free(content_copy);
		return ;
	}
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}
