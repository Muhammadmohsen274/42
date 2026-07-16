/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 17:37:01 by muali             #+#    #+#             */
/*   Updated: 2026/07/16 00:21:58 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_option(const char *arg, t_info *info)
{
	if (ft_strcmp(arg, "--simple") == 0)
		info->strategy = 1;
	else if (ft_strcmp(arg, "--medium") == 0)
		info->strategy = 2;
	else if (ft_strcmp(arg, "--complex") == 0)
		info->strategy = 3;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		info->strategy = 0;
	else if (ft_strcmp(arg, "--bench") == 0)
		info->bench = 1;
	else
		return (0);
	return (1);
}

static void	parse_number_string(const char *str, t_stack **a)
{
	char	**split;
	int		j;
	long	val;

	split = ft_split(str, ' ');
	if (!split || !split[0])
		print_error_and_exit();
	j = 0;
	while (split[j])
	{
		val = ft_atoi_check(split[j]);
		if (has_duplicate(*a, (int)val))
			print_error_and_exit();
		stack_add_back(a, stack_new((int)val));
		j++;
	}
	free_split(split);
}

int	parse_arguments(int argc, char **argv, t_stack **a, t_info *info)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!handle_option(argv[i], info))
			parse_number_string(argv[i], a);
		i++;
	}
	return (stack_size(*a));
}
