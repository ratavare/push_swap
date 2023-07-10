/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:45:17 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/31 16:32:33 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	static t_stack	stack;
	char			*instruction;

	if (argc == 1)
		return (0);
	if (argc >= 2)
		check_args(argv, &stack);
	get_values(&stack);
	instruction = get_next_line(0);
	while (instruction)
	{
		read_instructions(instruction, &stack);
		free (instruction);
		instruction = get_next_line(0);
	}
	free (instruction);
	if (is_sorted(&stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(&stack);
}

void	read_instructions(char	*instruction, t_stack *stack)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		sa(stack, 0);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		sb(stack, 0);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		ss(stack, 0);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		pa(stack, 0);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		pb(stack, 0);
	else if (ft_strncmp(instruction, "ra\n", 3) == 0)
		ra(stack, 0);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rb(stack, 0);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rr(stack, 0);
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		rra(stack, 0);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		rrb(stack, 0);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		rrr(stack, 0);
	else
		checker_error(instruction, stack);
}

void	checker_error(char	*s, t_stack *stack)
{
	write(2, "Error\n", 6);
	free (s);
	free_stacks(stack);
	exit (0);
}
