/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:43:20 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/31 15:39:49 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks wich sort algorithm to use depending
 on the size of the initial stack */

void	sort(t_stack *stack)
{
	if (stack->list_len <= 3)
		sort_3(stack);
	else if (stack->list_len < 6)
		sort_5(stack);
	else
		sort_big(stack);
}

/* Sorts 3 values */

void	sort_3(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->stack_a;
	if (tmp->content == stack->min_val)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (tmp->content == stack->max_val)
	{
		if (tmp->next->content == stack->min_val)
			ra(stack, 1);
		else
		{
			sa(stack, 1);
			rra(stack, 1);
		}
	}
	else
	{
		if (tmp->next->content == stack->min_val)
			sa(stack, 1);
		else
			rra(stack, 1);
	}
}

/* Sorts 5 values */

void	sort_5(t_stack *stack)
{
	if (stack->stack_a->next->content == stack->min_val)
		sa(stack, 1);
	else
		while (stack->stack_a->content != stack->min_val)
			rra(stack, 1);
	pb(stack, 1);
	if (stack->list_len != 3)
		sort_5(stack);
	if (!(is_sorted(stack)))
		sort_3(stack);
	if (stack->list_len == 3)
	{
		pa(stack, 1);
		pa(stack, 1);
	}
}

/* Sorts any stack with more than 5 elements */

void	sort_big(t_stack *stack)
{
	int	b_val;
	int	bf;

	push_below_mean(stack);
	sort_5(stack);
	while (stack->list_len2 != 0)
	{
		b_val = get_lowest_cost(stack);
		bf = get_bf(stack, b_val);
		put_on_top_b(stack, stack->stack_b, stack->list_len2, b_val);
		put_on_top_a(stack, stack->stack_a, stack->list_len, bf);
		pa(stack, 1);
	}
	while (stack->stack_a->content != stack->min_val)
		ra(stack, 1);
}
