/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:32:09 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/17 19:09:24 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_node(t_list **stack, int content)
{
	t_list	*new_node;
	t_list	*temp;
	int		*content_copy;

	content_copy = malloc(sizeof(int));
	if (!content_copy)
		return ;
	*content_copy = content;
	new_node = ft_lstnew(content_copy);
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
static void create_stack(int argc, char **argv, t_list **stack_a, t_list **stack_b)
{
	char	**temp_argv;

	*stack_b = NULL;
	if (argc == 2)
	{
		temp_argv = ft_split(argv[1], ' ');
		while (*temp_argv)
		{
			add_node(stack_a, ft_atol(*temp_argv));
			temp_argv++;
		}
	}
	else if (argc > 2)
	{
		while (*++argv)
			add_node(stack_a, ft_atol(*argv));
	}
}
static void	sort_prep(t_list **stack_a, t_list **stack_b)
{
	int	size_a;
	int	size_b;

	*stack_b = NULL;
	size_a = ft_lstsize(*stack_a);
	size_b = 0;
	if (size_a <= 3)
		short_sort(stack_a);
	else
	{
		push_one(stack_a, stack_b);
		size_b++;
		size_a--;
		push_one(stack_a, stack_b);
		size_b++;
		size_a--;
	}
	add_targets(stack_a, stack_b, 0);
	count_cost(stack_a, stack_b, &size_a, &size_b, 1);
	/*
	else
		turk_sort(tms) */
}

int main(int argc, char *argv[])
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (-1);
	error_checks(argc, argv);
	create_stack(argc, argv, &stack_a, &stack_b);
	sort_prep(&stack_a, &stack_b);
 	t_list *temp = stack_a;
	while (temp)
	{
		ft_printf("VALUE: %d ", *(int*)temp->content);
		ft_printf("TARGET: %d ", temp->target);
		ft_printf("COST: %d\n ", temp->cost);
		temp = temp->next;
	}
	return 0;
}
