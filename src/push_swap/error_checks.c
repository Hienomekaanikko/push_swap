/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:47:46 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/03 10:47:41 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

static void	values(long long num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoll(argv[i]) == num)
			error("Error");
		i++;
	}
}

static void	order(char **argv)
{
	int i;

	i = 0;
	while (argv[i + 1])
	{
		if (ft_atoll(argv[i]) >= ft_atoll(argv[i + 1]))
			return ;
		i++;
	}
	exit(0);
}


static void	isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			error("Error");
		i++;
	}
}

static void	free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
}

void	error_checks(int argc, char **argv)
{
	int		i;
	long long	nbr;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		nbr = ft_atoll(args[i]);
		isnum(args[i]);
		values(nbr, args, i);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error("Error");
		i++;
	}
	order(args);
	if (argc == 2)
		free_split(args);
}
