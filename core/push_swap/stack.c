/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 20:14:54 by muali             #+#    #+#             */
/*   Updated: 2026/07/16 00:23:01 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->rank = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*temp;

	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		return ;
	}
	temp = (*stack)->prev;
	temp->next = new_node;
	new_node->prev = temp;
	new_node->next = *stack;
	(*stack)->prev = new_node;
}

void	stack_clear(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*next;
	t_stack	*head;

	if (!stack || !*stack)
		return ;
	head = *stack;
	curr = head;
	while (1)
	{
		next = curr->next;
		free(curr);
		curr = next;
		if (curr == head)
			break ;
	}
	*stack = NULL;
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*curr;

	if (!stack)
		return (0);
	size = 0;
	curr = stack;
	while (1)
	{
		size++;
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (size);
}
