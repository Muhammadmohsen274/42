/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 11:53:17 by muali             #+#    #+#             */
/*   Updated: 2026/07/16 00:18:28 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	count_disorder(int *arr, int size)
{
	int		i;
	int		j;
	double	mistakes;
	double	total_pairs;

	mistakes = 0.0;
	total_pairs = 0.0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs += 1.0;
			if (arr[i] > arr[j])
				mistakes += 1.0;
			j++;
		}
		i++;
	}
	if (total_pairs == 0.0)
		return (0.0);
	return (mistakes / total_pairs);
}

double	compute_disorder(t_stack *a)
{
	int		size;
	int		*arr;
	t_stack	*curr;
	int		i;
	double	res;

	size = stack_size(a);
	if (size <= 1)
		return (0.0);
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (0.0);
	curr = a;
	i = 0;
	while (i < size)
	{
		arr[i] = curr->value;
		curr = curr->next;
		i++;
	}
	res = count_disorder(arr, size);
	free(arr);
	return (res);
}

void	sort_adaptive(t_stack **a, t_stack **b, t_info *info)
{
	if (info->disorder < 0.2)
		sort_simple(a, b, info);
	else if (info->disorder < 0.5)
		sort_medium(a, b, info);
	else
		sort_complex(a, b, info);
}
