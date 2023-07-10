/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:28:49 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/31 17:33:18 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Frees all allocated memory and displays an error message */

void	arg_error(char	*str, char	**args, t_stack *stack)
{
	if (str)
		ft_putstr_fd(str, 2);
	free_args(args);
	free_nodes(stack->stack_a);
	exit(0);
}

/* Displays an error message in case there are
 no arguments passed to the program */

void	no_args(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
