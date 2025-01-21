/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:47:46 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/17 10:14:06 by msuokas          ###   ########.fr       */
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

static int	order_check(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp->next != NULL)
	{
		if (*(int*)temp->content < *(int*)temp->next->content)
			temp = temp->next;
		else
			return (1);
	}
	return (0);
}

int		list_check(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) == 1)
		return (0);
	if (!order_check(stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		return(0);
	}
	if (find_duplicates(stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		return(0);
	}
	return (1);
}

static int	min_max_check(long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}
static int only_digit_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ((str[i] == '-' && str[i + 1] >= '0' && str[i + 1 <= '9'])
			|| (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9'))
			i++;
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 9 && str[i] <= 13)
			|| str[i] == 32)
			i++;
		else
			return (0);
	}
	return (1);
}
int	input_check(int argc, char **argv)
{
	char	**nums;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (!only_digit_check(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		while (*nums)
		{
			if (!min_max_check(ft_atol(*nums)))
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			nums++;
		}
	}
	i = 1;
	if (argc > 2)
	{
		while (argv[i])
		{
			if (!min_max_check(ft_atol(argv[i])))
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			i++;
		}
	}
	return (1);
}
