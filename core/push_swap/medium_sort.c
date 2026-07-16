/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 20:13:05 by muali             #+#    #+#             */
/*   Updated: 2026/07/16 00:20:17 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	int_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static void	push_all_to_b(t_stack **a, t_stack **b, int chunk, t_info *info)
{
	int	start;

	start = 0;
	while (*a)
	{
		if ((*a)->rank <= start)
		{
			pb(a, b, info, 1);
			start++;
		}
		else if ((*a)->rank <= start + chunk)
		{
			pb(a, b, info, 1);
			rb(b, info, 1);
			start++;
		}
		else
		{
			ra(a, info, 1);
		}
	}
}

static void	rotate_max_to_top(t_stack **b, t_info *info)
{
	t_stack	*max_node;
	t_stack	*curr;
	int		size_b;
	int		dist;

	max_node = get_max(*b);
	size_b = stack_size(*b);
	dist = 0;
	curr = *b;
	while (curr != max_node)
	{
		dist++;
		curr = curr->next;
	}
	if (dist <= size_b / 2)
	{
		while (*b != max_node)
			rb(b, info, 1);
	}
	else
	{
		while (*b != max_node)
			rrb(b, info, 1);
	}
}

static void	push_all_back_to_a(t_stack **a, t_stack **b, t_info *info)
{
	while (*b)
	{
		rotate_max_to_top(b, info);
		pa(a, b, info, 1);
	}
}

void	sort_medium(t_stack **a, t_stack **b, t_info *info)
{
	int	n;
	int	chunk;

	n = stack_size(*a);
	if (n <= 5)
	{
		sort_simple(a, b, info);
		return ;
	}
	chunk = int_sqrt(n);
	if (n <= 100)
		chunk = chunk * 1.5;
	else
		chunk = chunk * 1.6;
	push_all_to_b(a, b, chunk, info);
	push_all_back_to_a(a, b, info);
}
