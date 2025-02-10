/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:26:44 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/10 10:44:23 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	loop_input(char **args, int should_free, int i)
{
	long long	nbr;

	while (args[i])
	{
		nbr = ft_atoll(args[i]);
		if (!isnum(args[i]))
			error("Error", args, should_free);
		if (values(nbr, args, i))
			error("Error", args, should_free);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error("Error", args, should_free);
		i++;
	}
	if (order(args))
	{
		cleanup(args, should_free);
		exit(0);
	}
}

void	error_checks(int argc, char **argv)
{
	int			i;
	char		**args;
	int			should_free;

	i = 0;
	should_free = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		should_free = 1;
	}
	else
	{
		i = 1;
		args = argv;
	}
	loop_input(args, should_free, i);
	cleanup(args, should_free);
}

void	cleanup(char **args, int should_free)
{
	if (should_free)
	{
		ft_free_split(args);
		free(args);
	}
}
