/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:32:09 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/17 18:30:42 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_large(t_stack **a, t_stack **b)
{
	t_data	data;

	init_data_a(a, b, &data);
	fill(a, b, &data);
	init_data_b(a, b, &data);
	fill(b, a, &data);
	add_index(a);
	rotate_min_on_top(a);
}

static void	push_swap(t_stack **a, t_stack **b, size_t size_a)
{
	if (size_a > 4)
	{
		push(a, b, "pb");
		push(a, b, "pb");
		sort_large(a, b);
	}
	else if (size_a <= 3)
		sort_short(a, size_a);
	else if (size_a == 4)
	{
		push(a, b, "pb");
		sort_short(a, size_a);
		sort_large(a, b);
	}
}

static int	init_a(t_stack **a, int argc, char **argv)
{
	char	**split_argv;

	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
			return (0);
		if (!ft_make_list(a, split_argv))
		{
			ft_free_split(split_argv);
			return (0);
		}
		ft_free_split(split_argv);
	}
	else
	{
		if (!ft_make_list(a, ++argv))
			return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	size_t	size_a;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		validate_input(argc, argv);
		if (init_a(&a, argc, argv) == 0)
			ft_exit(&a, &b);
		size_a = ft_lstsize(a);
		push_swap(&a, &b, size_a);
	}
	free_stack(&a);
	return (0);
}
