/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:32:09 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/03 10:48:58 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_list **stack, long long content)
{
	t_list	*new_node;
	t_list	*temp;
	long long		*content_copy;

	content_copy = malloc(sizeof(long long));
	if (!content_copy)
		return ;
	*content_copy = content;
	new_node = ft_lstnew(content_copy);
	if (!new_node)
		return ;
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

static void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	if (size_a <= 3)
	{
		short_sort(stack_a);
		return ;
	}
	if (size_a == 4)
		push(stack_a, stack_b, "pb");
	else
	{
		while (size_b < 2)
		{
			push(stack_a, stack_b, "pb");
			(size_b)++;
			(size_a)--;
		}
	}
	long_sort(stack_a, stack_b);
}

static int	init_a(t_list **stack_a, int argc, char **argv)
{
	long long	num;

	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		while (*argv)
		{
			num = ft_atoll(*argv++);
			add_node(stack_a, num);
		}
	}
	else
	{
		while (*++argv)
		{
			num = ft_atoll(*argv);
			add_node(stack_a, num);
		}
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		error_checks(argc, argv);
		if (!init_a(&stack_a, argc, argv))
		{
			exit(0);
			return (1);
		}
		push_swap(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
