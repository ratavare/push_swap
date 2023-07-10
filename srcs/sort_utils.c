/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:47:07 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/31 14:55:17 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pushes all the values below stack a's mean value on to stack b*/

void	push_below_mean(t_stack *stack)
{
	while (stack->list_len != 5)
	{
		if (stack->stack_a->content < stack->mean_val)
			pb(stack, 1);
		else
			ra(stack, 1);
	}
}

/* Returns the value know as BF, wich is the minimum value in stack greater
 than the chosen value in stack b */

int	get_bf(t_stack *stack, int b_val)
{
	t_list	*tmp;
	int		bf;

	bf = 2147483647;
	tmp = stack->stack_a;
	while (tmp)
	{
		if (tmp->content > b_val && bf > tmp->content)
			bf = tmp->content;
		tmp = tmp->next;
	}
	return (bf);
}

/* Calculates and return wich pair of values (stack a paired with b)
 will have the least number of instructions for both values to be put on top
  of each stack*/

int	get_lowest_cost(t_stack *stack)
{
	t_list	*tmp_b;
	int		bf;
	int		lowestcost;
	int		cost;
	int		best_nbr;

	lowestcost = 2147483647;
	tmp_b = stack->stack_b;
	while (tmp_b)
	{
		bf = get_bf(stack, tmp_b->content);
		cost = get_cost(stack, bf, tmp_b->content);
		if (cost < lowestcost)
		{
			best_nbr = tmp_b->content;
			lowestcost = cost;
		}
		tmp_b = tmp_b->next;
	}
	return (best_nbr);
}

/* Calculates the cost of instructions for a pair of numbers to be put
 on top of it's stack */

int	get_cost(t_stack *stack, int bf, int b_val)
{
	t_list			*tmp_a;
	t_list			*tmp_b;
	static int		moves;

	tmp_a = stack->stack_a;
	tmp_b = stack->stack_b;
	moves = count_moves(tmp_a, stack->list_len, bf);
	moves += count_moves(tmp_b, stack->list_len2, b_val);
	return (moves);
}

/* Calculates the cost of instructions for a single value to be put on
 top of its own stack */

int	count_moves(t_list *head, int len, int val)
{
	int	count;

	count = 0;
	while (head->content != val)
	{
		count++;
		head = head->next;
	}
	if (count > (float)(len / 2))
		return (len - count);
	return (count);
}
