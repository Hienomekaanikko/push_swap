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
static int create_stack(int argc, char **argv)
{
	t_list	*stack_a;
	char	**temp_argv;

	stack_a = NULL;
	if (argc == 2)
	{
		temp_argv = ft_split(argv[1], ' ');
		while (*temp_argv)
		{
			add_node(&stack_a, ft_atol(*temp_argv));
			temp_argv++;
		}
	}
	else if (argc > 2)
	{
		while (*++argv)
			add_node(&stack_a, ft_atol(*argv));
	}
	if (!list_check(&stack_a))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		if (argv[1][0] == '\0')
			return (0);
		if (!input_check(argc, argv))
			return (0);
		if (!create_stack(argc, argv))
			return (0);
	}
	exit(0);
	return (0);
}
