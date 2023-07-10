/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:40:58 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/31 16:17:48 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Don't think this requires much explanation */

int	main(int argc, char **argv)
{
	static t_stack	stack;

	if (argc >= 2)
		check_args(argv, &stack);
	else
		no_args();
	get_values(&stack);
	if (!(is_sorted(&stack)))
		sort(&stack);
	free_stacks(&stack);
}
