/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 22:47:08 by muali             #+#    #+#             */
/*   Updated: 2026/07/16 00:14:20 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_info
{
	int		bench;
	int		strategy;
	double	disorder;
	int		op_counts[11];
	int		total_ops;
}	t_info;

# define OP_SA 0
# define OP_SB 1
# define OP_SS 2
# define OP_PA 3
# define OP_PB 4
# define OP_RA 5
# define OP_RB 6
# define OP_RR 7
# define OP_RRA 8
# define OP_RRB 9
# define OP_RRR 10

t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	stack_clear(t_stack **stack);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
t_stack	*get_max(t_stack *stack);
t_stack	*get_min(t_stack *stack);

void	sa(t_stack **a, t_info *info, int print);
void	sb(t_stack **b, t_info *info, int print);
void	ss(t_stack **a, t_stack **b, t_info *info, int print);
void	pa(t_stack **a, t_stack **b, t_info *info, int print);
void	pb(t_stack **a, t_stack **b, t_info *info, int print);
void	ra(t_stack **a, t_info *info, int print);
void	rb(t_stack **b, t_info *info, int print);
void	rr(t_stack **a, t_stack **b, t_info *info, int print);
void	rra(t_stack **a, t_info *info, int print);
void	rrb(t_stack **b, t_info *info, int print);
void	rrr(t_stack **a, t_stack **b, t_info *info, int print);

int		parse_arguments(int argc, char **argv, t_stack **a, t_info *info);
void	print_error_and_exit(void);
long	ft_atoi_check(const char *str);
char	**ft_split(const char *str, char c);
void	free_split(char **split);
int		ft_strcmp(const char *s1, const char *s2);
int		has_duplicate(t_stack *stack, int val);

double	compute_disorder(t_stack *a);
void	assign_ranks(t_stack *a);

void	sort_simple(t_stack **a, t_stack **b, t_info *info);
void	sort_medium(t_stack **a, t_stack **b, t_info *info);
void	sort_complex(t_stack **a, t_stack **b, t_info *info);
void	sort_adaptive(t_stack **a, t_stack **b, t_info *info);

#endif
