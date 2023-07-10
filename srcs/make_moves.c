/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:38:58 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/30 16:00:57 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Puts the value given as *int val* at the head of the stack 
 (only works for stack a) */

void	put_on_top_a(t_stack *stack, t_list *head, int len, int val)
{
	int	count;

	count = 0;
	while (head->content != val)
	{
		count++;
		head = head->next;
	}
	if (count > (float)(len / 2))
	{
		count = len - count;
		while (count-- != 0)
			rra(stack, 1);
	}
	else
	{
		while (count-- != 0)
			ra(stack, 1);
	}
}

/* Puts the value given as *int val* at the head of the stack
 (only works for stack b) */

void	put_on_top_b(t_stack *stack, t_list *head, int len, int val)
{
	int	count;

	count = 0;
	while (head->content != val)
	{
		count++;
		head = head->next;
	}
	if (count > (float)(len / 2))
	{
		count = len - count;
		while (count-- != 0)
			rrb(stack, 1);
	}
	else
	{
		while (count-- != 0)
			rb(stack, 1);
	}
}
