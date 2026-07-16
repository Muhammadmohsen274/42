/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 23:36:41 by muali             #+#    #+#             */
/*   Updated: 2026/07/16 00:14:47 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	assign_ranks(t_stack *a)
{
	t_stack	*curr;
	t_stack	*compare;
	int		rank;

	if (!a)
		return ;
	curr = a;
	while (1)
	{
		rank = 0;
		compare = a;
		while (1)
		{
			if (compare->value < curr->value)
				rank++;
			compare = compare->next;
			if (compare == a)
				break ;
		}
		curr->rank = rank;
		curr = curr->next;
		if (curr == a)
			break ;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
