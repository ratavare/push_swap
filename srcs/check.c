/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:20:46 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/31 17:32:46 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Splits all given arguments into an allocated "args" array and
 checks if the arguments are valid, if not, returns an error
 message, frees all allocated memory and exits the program. */

void	check_args(char **argv, t_stack *stack)
{
	static int		i;
	static int		j;
	char			**args;
	int				nbr;

	while (argv[++i])
	{
		args = ft_split(argv[i], 32);
		while (args[j])
		{
			nbr = ft_atoi(args[j]);
			if (!is_num(args[j]))
				arg_error("Error\n", args, stack);
			if (!is_overflow(nbr, args[j]))
				arg_error("Error\n", args, stack);
			if (!is_double(stack->stack_a, nbr))
				arg_error("Error\n", args, stack);
			ft_lstadd_back(&(stack->stack_a), ft_lstnew(nbr));
			j++;
		}
		free_args(args);
		j = 0;
	}
}

/* Returns 1 if the argument is a number. */

int	is_num(char	*num)
{
	int	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

/* Returns 1 if there are no repeated numbers. */

int	is_double(t_list *list, int number)
{
	while (list)
	{
		if (number == list->content)
			return (0);
		list = list->next;
	}
	return (1);
}

/* Return 1 if there isn't an integer overflow */

int	is_overflow(int nbr, char *arg)
{
	int		i;
	char	*nbr2;

	i = 0;
	nbr2 = ft_itoa(nbr);
	while (nbr2[i] || arg[i])
	{
		if (nbr2[i] != arg[i])
		{
			free (nbr2);
			return (0);
		}
		i++;
	}
	free (nbr2);
	return (1);
}

/* Checks if stack a is sorted */

int	is_sorted(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
