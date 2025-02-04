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

	if (!content)
		return ;
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

static void	push_swap(t_list **a, t_list **b)
{
	int	size_a;

	size_a = ft_lstsize(*a);
	if (size_a > 3)
	{
		push(a, b, "pb");
		push(a, b, "pb");
		long_sort(a, b);
	}
	else if (size_a <= 3)
		short_sort(a);
}

static void	init_a(t_list **a, int argc, char **argv)
{
	long long	num;

	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		while (*argv)
		{
			num = ft_atoll(*argv++);
			add_node(a, num);
		}
	}
	else
	{
		while (*++argv)
		{
			num = ft_atoll(*argv);
			add_node(a, num);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		error_checks(argc, argv);
		init_a(&a, argc, argv);
		push_swap(&a, &b);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
