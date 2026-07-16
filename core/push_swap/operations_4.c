/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 23:07:56 by muali             #+#    #+#             */
/*   Updated: 2026/07/16 00:21:38 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	*stack = (*stack)->prev;
}

void	rra(t_stack **a, t_info *info, int print)
{
	reverse_rotate(a);
	info->op_counts[OP_RRA]++;
	info->total_ops++;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, t_info *info, int print)
{
	reverse_rotate(b);
	info->op_counts[OP_RRB]++;
	info->total_ops++;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, t_info *info, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	info->op_counts[OP_RRR]++;
	info->total_ops++;
	if (print)
		write(1, "rrr\n", 4);
}
