/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:47:46 by msuokas           #+#    #+#             */
/*   Updated: 2025/02/10 11:10:15 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	values(long long num, char **argv, int i)
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

int	order(char **argv)
{
	int	i;

	i = 0;
	while (argv[i + 1])
	{
		if (ft_atoll(argv[i]) >= ft_atoll(argv[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	isnum(char *num)
{
	int	i;

	i = 0;
	while (num[i] && ft_isspace(num[i]))
		i++;
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (!ft_isdigit(num[i]))
		return (0);
	while (num[i] && ft_isdigit(num[i]))
		i++;
	while (num[i])
	{
		if (!ft_isspace(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	error(char *msg, char **args, int should_free)
{
	cleanup(args, should_free);
	ft_putendl_fd(msg, 2);
	exit(1);
}
