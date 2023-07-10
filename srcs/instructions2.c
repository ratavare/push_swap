/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:43:10 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/31 16:15:04 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shifts up all elements of stack a by 1.

int	ra(t_stack *stack, int flag)
{
	t_list	*tail;
	t_list	*head;

	if (stack->list_len < 2)
		return (0);
	head = stack->stack_a;
	tail = ft_lstlast(head);
	stack->stack_a = stack->stack_a->next;
	head->next = NULL;
	tail->next = head;
	if (flag == 1)
		ft_printf("ra\n");
	return (0);
}

// Shifts up all elements of stack b by 1.

int	rb(t_stack *stack, int flag)
{
	t_list	*tail;
	t_list	*head;

	if (stack->list_len2 < 2)
		return (0);
	head = stack->stack_b;
	tail = ft_lstlast(head);
	stack->stack_b = stack->stack_b->next;
	head->next = NULL;
	tail->next = head;
	if (flag == 1)
		ft_printf("rb\n");
	return (0);
}

// ra and rb at the same time.

int	rr(t_stack *stack, int flag)
{
	if (stack->list_len2 < 2 || stack->list_len < 2)
		return (0);
	ra(stack, 0);
	rb(stack, 0);
	if (flag == 1)
		ft_printf("rr\n");
	return (0);
}
