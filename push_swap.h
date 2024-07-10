/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:05:05 by hutzig            #+#    #+#             */
/*   Updated: 2024/07/10 11:59:25 by hutzig           ###   ########.fr       */
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
	int				nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*stack_processing(int argc, char **argv, t_stack *a);
void	stack_sorting(t_stack **a, t_stack **b);
void	sorting_three(t_stack **a);
void	sorting_small(t_stack **a, t_stack **b);
void	sorting_big(t_stack **a, t_stack **b);

// utils
t_stack	*ft_stack_last(t_stack **stack);
int		ft_stack_size(t_stack **stack);
int		ft_stack_min(t_stack **stack);
int		ft_stack_max(t_stack **stack);
int		ft_stack_position(t_stack **stack, int nb);

// operations
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);

// checkings
bool	stack_sorting_check(t_stack **a);
bool	stack_checking_dup(t_stack *a);
bool	checking_syntax_error(char *str);
bool	checking_is_integer(char *str);

// error and free
void	ft_error(void);
void	ft_free_array(char **args);
void	ft_free_stack(t_stack **a);
void	exit_success(t_stack **a, t_stack **b);
void	exit_failure(t_stack **a, t_stack **b);

#endif
