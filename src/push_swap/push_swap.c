/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:32:09 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/08 15:55:40 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_list **stack, int content)
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

void del(void *content)
{
	free(content);
}

// void	pb(t_list *stack_a, t_list *stack_b)
// {
// 	t_list	*temp;
// 	t_list	*temp_b;

// 	temp = stack_a;
// 	temp_b = stack_b;
// 	add_node(temp_b, *(int *)temp->content);
// 	temp = temp->next;
// 	ft_lstdelone(temp, del);
// 	stack_a = temp;
// }

void	push_swap(t_list **stack)
{
	t_list	*stack_b;
	t_list	*curr;
	t_list	*temp;
	int	list_len;
	int	count;

	curr = *stack;
	stack_b = NULL;
	list_len = ft_lstsize(curr);
	count = 0;
	//check that list_len works
	//ft_printf("%d \n", list_len);
	if (list_len > 3)
	{
		while (count < 2)
		{
			temp = curr;
			add_node(&stack_b, *(int *)curr->content);
			curr = curr->next;
			ft_lstdelone(temp, del);
			count++;
		}
		*stack = curr;
	}
	temp = stack_b;
	ft_printf("%s\n", "Stack B: ");
	while (temp)
	{
		ft_printf("%d ", *(int *)temp->content);
		temp = temp->next;
	}
	ft_printf("\n");
}

int	main(int argc, char *argv[])
{
	int		i;
	t_list	*stack_a;
	t_list	*temp;

	i = 1;
	stack_a = NULL;
	if (argc > 1)
	{
		while (argv[i])
		{
			add_node(&stack_a, ft_atoi(argv[i]));
			i++;
		}
		push_swap(&stack_a);
	}
	temp = stack_a;
	ft_printf("%s\n", "Stack A: ");
	while (temp)
	{
		ft_printf("%d ", *(int *)temp->content);
		temp = temp->next;
	}
	ft_printf("\n");
	return (0);
}
