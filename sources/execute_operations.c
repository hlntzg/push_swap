/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:16:42 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/15 16:50:13 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_operations_ra_rb(t_stack **a, t_stack **b, t_stack *node)
{
	while (a->nb != node->nb && b->nb != target_in_b(a, b)->nb)
		rr(a, b);
	while (a->nb != node->nb)
		ra(a);
	while (b->nb != target_in_b(a, b)->nb)
		rb(b);
	pb(a, b); 
}

void	execute_operations_rra_rrb(t_stack **a, t_stack **b, t_stack *node)
{
	while (a->nb != node->nb && b->nb != target_in_b(a, b)->nb)
		rrr(a, b);
	while (a->nb != node->nb)
		rra(a);
	while (b->nb != target_in_b(a, b)->nb)
		rrb(b);
	pb(a, b);
}

void	execute_operations_ra_rrb(t_stack **a, t_stack **b, t_stack *node)
{
	while (a->nb != node->nb)
		ra(a);
	while (b->nb != target_in_b(a, b)->nb)
		rrb(b);
	pb(a, b);
}

void	execute_operations_rra_rb(t_stack **a, t_stack **b, t_stack *node)
{
	while (a->nb != node->nb)
		rra(a);
	while (b->nb != target_in_b(a, b)->nb)
		rb(b);
	pb(a, b);
}
