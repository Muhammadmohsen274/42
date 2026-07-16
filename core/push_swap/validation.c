/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 02:27:48 by muali             #+#    #+#             */
/*   Updated: 2026/07/16 00:24:28 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_stack *stack, int val)
{
	t_stack	*curr;

	if (!stack)
		return (0);
	curr = stack;
	while (1)
	{
		if (curr->value == val)
			return (1);
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	return (0);
}

long	ft_atoi_check(const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = (str[0] == '-' || str[0] == '+');
	if (str[0] == '-')
		sign = -1;
	if (!str[i])
		print_error_and_exit();
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			print_error_and_exit();
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX)
			|| (sign == -1 && num > 2147483648L))
			print_error_and_exit();
		i++;
	}
	return (num * sign);
}
