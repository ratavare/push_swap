/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:37:36 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/30 16:09:15 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Frees all arguments allocated by ft_split */

void	free_args(char	**args)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i])
			free (args[i++]);
		free (args);
	}
}

/* Frees all nodes in a linked list */

void	free_nodes(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head->next;
		free (head);
		head = tmp;
	}
}

/* Frees both lists in the *stack* structure */

void	free_stacks(t_stack *stack)
{
	free_nodes(stack->stack_a);
	free_nodes(stack->stack_b);
}

/* Utilitary function to print a list from start to end */

void	print_list(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}
