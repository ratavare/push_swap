/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:06:13 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/30 15:58:31 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Defines all the variables in the t_stack stack structure */

void	get_values(t_stack *stack)
{
	stack->list_len = ft_lstsize(stack->stack_a);
	stack->list_len2 = ft_lstsize(stack->stack_b);
	get_min_val(stack);
	get_max_val(stack);
	get_mean_val(stack);
}

/* Defines the minimum value present in the list stack a */

void	get_min_val(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->stack_a;
	stack->min_val = tmp->content;
	while (tmp)
	{
		if (tmp->content < stack->min_val)
			stack->min_val = tmp->content;
		tmp = tmp->next;
	}
}

/* Defines the maximum value present in the list stack b */

void	get_max_val(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->stack_a;
	stack->max_val = tmp->content;
	while (tmp)
	{
		if (tmp->content > stack->max_val)
			stack->max_val = tmp->content;
		tmp = tmp->next;
	}
}

/* Defines the mean value for stack a */

void	get_mean_val(t_stack *stack)
{
	t_list	*tmp;
	float	sum;
	float	count;

	sum = 0;
	count = 0;
	tmp = stack->stack_a;
	while (tmp)
	{
		sum += tmp->content;
		count++;
		tmp = tmp->next;
	}
	stack->mean_val = sum / count;
}
