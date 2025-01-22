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

static void	add_node(t_list **stack, long long content)
{
	t_list			*new_node;
	t_list			*temp;
	long long		*content_copy;

	content_copy = malloc(sizeof(long long));
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
			add_node(stack_a, ft_atoll(*temp_argv));
			temp_argv++;
		}
	}
	else if (argc > 2)
	{
		while (*++argv)
			add_node(stack_a, ft_atoll(*argv));
	}
}

static void	medium_sort(t_list **stack_a, t_list **stack_b)
{
	push_one(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
	short_sort(stack_a);
	add_targets(stack_b, stack_a, 1);
	while (*(long long*)(*stack_a)->content != (*stack_b)->target)
	{
		rotate_one_up(stack_a);
		ft_putendl_fd("ra", 1);
	}
	push_one(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
	rotate_min_on_top(stack_a);
}

static void	sort_prep(t_list **stack_a, t_list **stack_b)
{
	int	size_a;
	int	size_b;

	if (*stack_a == NULL)
		return ;
	*stack_b = NULL;
	size_a = ft_lstsize(*stack_a);
	size_b = 0;
	if (size_a == 3)
		short_sort(stack_a);
	else if (size_a == 4)
		medium_sort(stack_a, stack_b);
	else
		full_sort(stack_a, stack_b, &size_a, &size_b);
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
/* 	t_list *temp = stack_a;
	while (temp)
	{
		ft_printf("VALUE: %d ", *(int*)temp->content);
		ft_printf("TARGET: %d ", temp->target);
		ft_printf("COST: %d\n ", temp->cost);
		temp = temp->next;
	} */
	return 0;
}
