/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:32:09 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/10 11:00:59 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_list **a, t_list **b)
{
	int	size_a;

	size_a = ft_lstsize(*a);
	if (size_a > 4)
	{
		push(a, b, "pb");
		push(a, b, "pb");
		long_sort(a, b);
	}
	else if (size_a <= 3)
		short_sort(a);
	else if (size_a == 4)
	{
		push(a, b, "pb");
		short_sort(a);
		long_sort(a, b);
	}
}

void	make_list(t_list **a, char **content)
{
	long long	num;

	while (*content)
	{
		num = ft_atoll(*content);
		add_node(a, num);
		content++;
	}
}

static int	init_a(t_list **a, int argc, char **argv)
{
	char		**split_argv;
	char		**original_split_argv;

	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
			return (0);
		original_split_argv = split_argv;
		make_list(a, split_argv);
		ft_free_split(original_split_argv);
		free(original_split_argv);
	}
	else
		make_list(a, ++argv);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		if (argc == 2 && ft_strlen(argv[1]) == 0)
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		error_checks(argc, argv);
		init_a(&a, argc, argv);
		push_swap(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
