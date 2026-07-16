/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 21:37:57 by muali             #+#    #+#             */
/*   Updated: 2026/07/16 00:17:22 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	init_info(t_info *info)
{
	int	i;

	info->bench = 0;
	info->strategy = 0;
	info->total_ops = 0;
	i = 0;
	while (i < 11)
		info->op_counts[i++] = 0;
}

static void	print_bench(t_info *i)
{
	char	*s;

	s = "adaptive (complex) / O(n log n)";
	if (i->strategy == 1)
		s = "simple / O(n^2)";
	else if (i->strategy == 2)
		s = "medium / O(n sqrt(n))";
	else if (i->strategy == 3)
		s = "complex / O(n log n)";
	else if (i->disorder < 0.2)
		s = "adaptive (simple) / O(n^2)";
	else if (i->disorder < 0.5)
		s = "adaptive (medium) / O(n sqrt(n))";
	fprintf(stderr, "[bench] disorder: %.2f%%\n", i->disorder * 100.0);
	fprintf(stderr, "[bench] strategy: %s\n", s);
	fprintf(stderr, "[bench] total_ops: %d\n", i->total_ops);
	fprintf(stderr, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		i->op_counts[OP_SA], i->op_counts[OP_SB], i->op_counts[OP_SS],
		i->op_counts[OP_PA], i->op_counts[OP_PB]);
	fprintf(stderr, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		i->op_counts[OP_RA], i->op_counts[OP_RB], i->op_counts[OP_RR],
		i->op_counts[OP_RRA], i->op_counts[OP_RRB], i->op_counts[OP_RRR]);
}

static void	dispatch_sort(t_stack **a, t_stack **b, t_info *info)
{
	if (is_sorted(*a))
		return ;
	if (info->strategy == 1)
		sort_simple(a, b, info);
	else if (info->strategy == 2)
		sort_medium(a, b, info);
	else if (info->strategy == 3)
		sort_complex(a, b, info);
	else
		sort_adaptive(a, b, info);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_info	info;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	init_info(&info);
	if (parse_arguments(argc, argv, &a, &info) == 0)
		return (0);
	info.disorder = compute_disorder(a);
	assign_ranks(a);
	dispatch_sort(&a, &b, &info);
	if (info.bench)
		print_bench(&info);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
