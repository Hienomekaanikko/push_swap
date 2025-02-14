/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:47:46 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/14 18:06:41 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	values(long long num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoll(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	order(char **args, int i, int should_free)
{
	while (args[i] && args[i + 1])
	{
		if (ft_atoll(args[i]) >= ft_atoll(args[i + 1]))
			return (0);
		i++;
	}
	if (should_free)
		ft_free_split(args);
	exit(0);
}

static void	loop_input(char **args, int should_free, int i)
{
	long long	nbr;
	int			j;
	int			space_flag;

	j = i;
	space_flag = 0;
	while (args[i])
	{
		nbr = ft_atoll(args[i]);
		if (!ft_isspace(*args[i]))
			space_flag = 1;
		if (!ft_isnum(args[i]))
			error("Error", args, should_free);
		if (values(nbr, args, i))
			error("Error", args, should_free);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error("Error", args, should_free);
		i++;
	}
	if (space_flag == 0)
		error("Error", args, should_free);
	order(args, j, should_free);
}

void	parse_input(int argc, char **argv)
{
	int			i;
	char		**args;
	int			should_free;

	i = 0;
	should_free = 0;
	if (argc == 2)
	{
		if (!argv[1][0])
			return ;
		args = ft_split(argv[1], ' ');
		if (!args)
			return ;
		should_free = 1;
	}
	else
	{
		i = 1;
		args = argv;
	}
	loop_input(args, should_free, i);
	if (should_free)
		ft_free_split(args);
}
