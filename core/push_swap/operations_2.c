/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 22:29:13 by muali             #+#    #+#             */
/*   Updated: 2026/07/16 00:21:08 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*pop_src(t_stack **src)
{
	t_stack	*node;

	if (!src || !*src)
		return (NULL);
	node = *src;
	if (node->next == node)
		*src = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		*src = node->next;
	}
	return (node);
}

static void	push_dst(t_stack *node, t_stack **dst)
{
	if (!node)
		return ;
	if (!*dst)
	{
		*dst = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = *dst;
		node->prev = (*dst)->prev;
		node->prev->next = node;
		(*dst)->prev = node;
		*dst = node;
	}
}

void	pa(t_stack **a, t_stack **b, t_info *info, int print)
{
	t_stack	*node;

	node = pop_src(b);
	push_dst(node, a);
	info->op_counts[OP_PA]++;
	info->total_ops++;
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, t_info *info, int print)
{
	t_stack	*node;

	node = pop_src(a);
	push_dst(node, b);
	info->op_counts[OP_PB]++;
	info->total_ops++;
	if (print)
		write(1, "pb\n", 3);
}
