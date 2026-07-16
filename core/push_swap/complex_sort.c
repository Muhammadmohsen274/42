/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 11:59:46 by muali             #+#    #+#             */
/*   Updated: 2026/07/16 00:18:48 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_pass(t_stack **a, t_stack **b, int bit, t_info *info)
{
	int	j;
	int	top_rank;
	int	size;

	size = stack_size(*a);
	j = 0;
	while (j < size)
	{
		top_rank = (*a)->rank;
		if (((top_rank >> bit) & 1) == 0)
			pb(a, b, info, 1);
		else
			ra(a, info, 1);
		j++;
	}
	while (*b)
		pa(a, b, info, 1);
}

void	sort_complex(t_stack **a, t_stack **b, t_info *info)
{
	int	size;
	int	max_bits;
	int	i;

	size = stack_size(*a);
	if (size <= 5)
	{
		sort_simple(a, b, info);
		return ;
	}
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		radix_pass(a, b, i, info);
		i++;
	}
}
