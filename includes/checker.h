/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:45:19 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/31 15:02:41 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "../libft/get_next_line/get_next_line.h"

void	read_instructions(char	*instruction, t_stack *stack);
void	checker_error(char	*s, t_stack *stack);

#endif