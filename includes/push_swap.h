/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:41:13 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/31 14:56:10 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/srcs/ft_printf.h"

typedef struct s_stack
{
	int		list_len;
	int		list_len2;
	int		min_val;
	int		max_val;
	float	mean_val;
	t_list	*stack_a;
	t_list	*stack_b;
}			t_stack;

// check.c
void	check_args(char **argv, t_stack *stack);
int		is_num(char	*num);
int		is_double(t_list *list, int number);
int		is_overflow(int nbr, char *arg);
int		is_sorted(t_stack *stack);

// error.c
void	arg_error(char	*str, char	**args, t_stack *stack);
void	no_args(void);

// utils.c
void	free_args(char	**args);
void	free_nodes(t_list *head);
void	free_stacks(t_stack *stack);
void	print_list(t_list *head);

// instructions.c
int		sa(t_stack *stack, int flag);
int		sb(t_stack *stack, int flag);
int		ss(t_stack *stack, int flag);
int		pa(t_stack *stack, int flag);
int		pb(t_stack *stack, int flag);

// instructions2.c
int		ra(t_stack *stack, int flag);
int		rb(t_stack *stack, int flag);
int		rr(t_stack *stack, int flag);

// instructions3.c
int		rra(t_stack *stack, int flag);
int		rrb(t_stack *stack, int flag);
int		rrr(t_stack *stack, int flag);

// get_values.c
void	get_values(t_stack *stack);
void	get_min_val(t_stack *stack);
void	get_max_val(t_stack *stack);
void	get_mean_val(t_stack *stack);

// sort.c
void	sort(t_stack *stack);
void	sort_3(t_stack *stack);
void	sort_5(t_stack *stack);
void	sort_big(t_stack *stack);

// sort_utils.c
void	push_below_mean(t_stack *stack);
int		get_bf(t_stack *stack, int b_val);
int		get_lowest_cost(t_stack *stack);
int		get_cost(t_stack *stack, int bf, int b_val);
int		count_moves(t_list *head, int len, int val);

// make_moves.c
void	put_on_top_b(t_stack *stack, t_list *head, int len, int val);
void	put_on_top_a(t_stack *stack, t_list *head, int len, int val);
#endif