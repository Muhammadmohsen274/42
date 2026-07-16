/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 01:17:45 by muali             #+#    #+#             */
/*   Updated: 2026/07/16 00:14:37 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **a, t_info *info)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a, info, 1);
	else if (x > y && y > z)
	{
		sa(a, info, 1);
		rra(a, info, 1);
	}
	else if (x > y && y < z && x > z)
		ra(a, info, 1);
	else if (x < y && y > z && x < z)
	{
		sa(a, info, 1);
		ra(a, info, 1);
	}
	else if (x < y && y > z && x > z)
		rra(a, info, 1);
}

static void	push_min_to_b(t_stack **a, t_stack **b, t_info *info)
{
	t_stack	*min_node;
	t_stack	*curr;
	int		dist;
	int		size;

	min_node = get_min(*a);
	dist = 0;
	curr = *a;
	while (curr != min_node)
	{
		dist++;
		curr = curr->next;
	}
	size = stack_size(*a);
	if (dist <= size / 2)
	{
		while (*a != min_node)
			ra(a, info, 1);
	}
	else
	{
		while (*a != min_node)
			rra(a, info, 1);
	}
	pb(a, b, info, 1);
}

static void	sort_small(t_stack **a, t_stack **b, t_info *info)
{
	while (stack_size(*a) > 3)
		push_min_to_b(a, b, info);
	sort_three(a, info);
	while (*b)
		pa(a, b, info, 1);
}

void	sort_simple(t_stack **a, t_stack **b, t_info *info)
{
	int	size;

	size = stack_size(*a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, info, 1);
		return ;
	}
	if (size <= 5)
	{
		sort_small(a, b, info);
		return ;
	}
	while (!is_sorted(*a))
		push_min_to_b(a, b, info);
	while (*b)
		pa(a, b, info, 1);
}
