/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:35:27 by hutzig            #+#    #+#             */
/*   Updated: 2024/07/04 09:42:13 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shift_up_elements(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

// ra: shift up all elements of stack A by 1, the first become the last one
void	ra(t_stack **a)
{
	if (!(*a) || !(*a)->next)
		return ;
	shift_up_elements(a);
	write(1, "ra\n", 3);
}

// rb: shift up all elements of stack B by 1, the first become the last one
void	rb(t_stack **b)
{
	if (!(*b) || !(*b)->next)
		return ;
	shift_up_elements(b);
	write(1, "rb\n", 3);
}

// rr: ra & rb at the same time
void	rr(t_stack **a, t_stack **b)
{
	if (!(*a) || !(*b) || !(*a)->next || !(*b)->next)
		return ;
	shift_up_elements(a);
	shift_up_elements(a);
	write (1, "rr\n", 3);
}
