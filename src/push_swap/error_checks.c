/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:47:46 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/23 09:51:55 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	values(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	order(char **argv)
{
	int i;

	i = 0;
	while (argv[i + 1])
	{
		if (ft_atoi(argv[i]) >= ft_atoi(argv[i + 1]))
			return (0);
		i++;
	}
	return (1);
}


static int	isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
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
		if (!isnum(args[i]))
			error("Error");
		if (values(nbr, args, i))
			error("Error");
		if (nbr < INT_MIN || nbr > INT_MAX)
			error("Error");
		i++;
	}
	if (order(args) == 1)
		exit(0);
	if (argc == 2)
		free_split(args);
}
