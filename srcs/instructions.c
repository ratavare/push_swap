/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:46:51 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/31 14:54:26 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swaps the first 2 elements at the top of stack a.

int	sa(t_stack *stack, int flag)
{
	t_list	*tmp;

	if (stack->stack_a->next == NULL)
		return (0);
	tmp = stack->stack_a->next;
	stack->stack_a->next = stack->stack_a->next->next;
	tmp->next = stack->stack_a;
	stack->stack_a = tmp;
	if (flag == 1)
		ft_printf("sa\n");
	return (0);
}

// Swaps the first 2 elements at the top of stack b.

int	sb(t_stack *stack, int flag)
{
	t_list	*tmp;

	if (stack->stack_b->next == NULL)
		return (0);
	tmp = stack->stack_b->next;
	stack->stack_b->next = stack->stack_b->next->next;
	tmp->next = stack->stack_b;
	stack->stack_b = tmp;
	if (flag == 1)
		ft_printf("sb\n");
	return (0);
}

// sa and sb at the same time.

int	ss(t_stack *stack, int flag)
{
	sa(stack, 0);
	sb(stack, 0);
	if (flag == 1)
		ft_printf("ss\n");
	return (0);
}

// Takes the first element at the top of b and put it at the top of a.

int	pa(t_stack *stack, int flag)
{
	t_list	*tmp;

	tmp = stack->stack_b;
	if (stack->stack_b == NULL)
		return (0);
	ft_lstadd_front(&(stack->stack_a), ft_lstnew(stack->stack_b->content));
	stack->stack_b = stack->stack_b->next;
	free(tmp);
	get_values(stack);
	if (flag == 1)
		ft_printf("pa\n");
	return (0);
}

// Takes the first element at the top of a and put it at the top of b.

int	pb(t_stack *stack, int flag)
{
	t_list	*tmp;

	tmp = stack->stack_a;
	if (stack->stack_a == NULL)
		return (0);
	ft_lstadd_front(&(stack->stack_b), ft_lstnew(stack->stack_a->content));
	stack->stack_a = stack->stack_a->next;
	free(tmp);
	get_values(stack);
	if (flag == 1)
		ft_printf("pb\n");
	return (0);
}
