/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:47:46 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/10 14:47:13 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_duplicates(t_list **stack_a)
{
	t_list *current;
	t_list *runner;

	current = *stack_a;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (*(int *)current->content == *(int *)runner->content)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	error_check(t_list	**stack_a)
{
	if (find_duplicates(stack_a))
		return (0);
	return (1);
}

