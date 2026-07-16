/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 22:36:46 by muali             #+#    #+#             */
/*   Updated: 2026/07/16 00:21:25 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	*stack = (*stack)->next;
}

void	ra(t_stack **a, t_info *info, int print)
{
	rotate(a);
	info->op_counts[OP_RA]++;
	info->total_ops++;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, t_info *info, int print)
{
	rotate(b);
	info->op_counts[OP_RB]++;
	info->total_ops++;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, t_info *info, int print)
{
	rotate(a);
	rotate(b);
	info->op_counts[OP_RR]++;
	info->total_ops++;
	if (print)
		write(1, "rr\n", 3);
}
