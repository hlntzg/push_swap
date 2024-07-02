/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:05:05 by hutzig            #+#    #+#             */
/*   Updated: 2024/07/02 16:13:44 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h> // WRITE
# include <stdlib.h> // MALLOC, EXIT
# include <limits.h> // INT_MIX & INT_MAX
# include <stdbool.h> // bool data type

# include <stdio.h>

typedef struct s_stack
{
	int		nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*stack_processing(int argc, char **argv);
void	stack_sorting(t_stack **a, t_stack **b);

bool	stack_sorting_check(t_stack **a);
bool	stack_checking_dup(t_stack *a);
bool	checking_syntax_error(char *str);
bool	checking_is_integer(char *str);

void	ft_error(void);
void	ft_free_array(char **args);
void	ft_free_stack(t_stack **a);

#endif
