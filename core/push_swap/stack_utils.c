/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 22:09:44 by muali             #+#    #+#             */
/*   Updated: 2026/07/16 00:17:40 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*curr;

	if (!stack)
		return (1);
	curr = stack;
	while (curr->next != stack)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

t_stack	*get_max(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*max;

	if (!stack)
		return (NULL);
	max = stack;
	curr = stack->next;
	while (curr != stack)
	{
		if (curr->value > max->value)
			max = curr;
		curr = curr->next;
	}
	return (max);
}

t_stack	*get_min(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*min;

	if (!stack)
		return (NULL);
	min = stack;
	curr = stack->next;
	while (curr != stack)
	{
		if (curr->value < min->value)
			min = curr;
		curr = curr->next;
	}
	return (min);
}
