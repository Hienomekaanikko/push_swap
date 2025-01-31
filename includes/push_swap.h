/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:41:40 by msuokas           #+#    #+#             */
/*   Updated: 2025/01/31 15:17:07 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define	PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

typedef struct	s_data
{
	int	cheapest;
	int	src_median;
	int	dst_median;
	int	src_index;
	int	dst_index;
	int	stack_flag;
	int	src_size;
	int	dst_size;
	int	highest;
	int	lowest;
	int	both;
}	t_data;

void	s(t_list **stack_src, const char *operation);
void	push(t_list **stack_src, t_list **stack_dst, const char *operations);
void	rotate(t_list **stack_a, const char *operation);
void	reverse(t_list **stack, const char *operation);
void	add_targets(t_list **stack_src, t_list **stack_dst, t_data *data);
void	long_sort(t_list **stack_a, t_list **stack_b, int *size_a, int *size_b);
void	rotate_max_on_top(t_list **stack);
long long	highest(t_list **stack);
long long	lowest(t_list **stack);
void	reverse_both(t_list **stack_src, t_list **stack_dst, const char *operation, t_data *data);
void	rotate_both(t_list **stack_src, t_list **stack_dst, const char *operation, t_data *data);
void	short_sort(t_list **stack_a);
void	free_stack(t_list **stack);
void	rotate_min_on_top(t_list **stack);
void	error_checks(int argc, char **argv);
int		find_cheapest(t_list **stack);
void	rotate_dst(t_list **stack_dst, t_data *data);
void	rotate_src(t_list **stack_src, t_data *data);
void	reverse_dst(t_list **stack_dst, t_data *data);
void	reverse_src(t_list **stack_src, t_data *data);
void	other_case(t_list **stack_src, t_data *data);
int		src_to_top_dist(int cheapest, t_list **src);
int		dst_to_top_dist(int cheapest, t_list **src, t_list **dest);
long long	lowest(t_list **stack);

#endif
