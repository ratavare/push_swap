/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:51:43 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/31 16:31:09 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shifts down all elements of stack a by 1.

int	rra(t_stack *stack, int flag)
{
	t_list	*tail;
	t_list	*head;

	if (stack->list_len < 2)
		return (0);
	head = stack->stack_a;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = stack->stack_a;
	stack->stack_a = tail;
	if (flag == 1)
		ft_printf("rra\n");
	return (0);
}

// Shifts down all elements of stack b by 1.

int	rrb(t_stack *stack, int flag)
{
	t_list	*tail;
	t_list	*head;

	if (stack->list_len2 < 2)
		return (0);
	head = stack->stack_b;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = stack->stack_b;
	stack->stack_b = tail;
	if (flag == 1)
		ft_printf("rrb\n");
	return (0);
}

// rra and rrb at the same time.

int	rrr(t_stack *stack, int flag)
{
	if (stack->list_len < 2 || stack->list_len2 < 2)
		return (0);
	rra(stack, 0);
	rrb(stack, 0);
	if (flag == 1)
		ft_printf("rrr\n");
	return (0);
}
