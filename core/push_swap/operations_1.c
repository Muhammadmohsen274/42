/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 20:31:22 by muali             #+#    #+#             */
/*   Updated: 2026/07/16 00:20:47 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*last;

	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = first->next;
	if (second->next == first)
	{
		*stack = second;
		return ;
	}
	third = second->next;
	last = first->prev;
	first->next = third;
	third->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = last;
	last->next = second;
	*stack = second;
}

void	sa(t_stack **a, t_info *info, int print)
{
	swap(a);
	info->op_counts[OP_SA]++;
	info->total_ops++;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, t_info *info, int print)
{
	swap(b);
	info->op_counts[OP_SB]++;
	info->total_ops++;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, t_info *info, int print)
{
	swap(a);
	swap(b);
	info->op_counts[OP_SS]++;
	info->total_ops++;
	if (print)
		write(1, "ss\n", 3);
}
