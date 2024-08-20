/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:16:42 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/20 12:48:16 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_operations_ra_rb(t_stack **a, t_stack **b, t_stack *node)
{
	while ((*a)->nb != node->nb || (*b)->nb != target_in_b(b, node)->nb)
		rr(a, b);
	while ((*a)->nb != node->nb)
		ra(a);
	while ((*b)->nb != target_in_b(b, node)->nb)
		rb(b);
	pb(a, b); 
}

void	execute_operations_rra_rrb(t_stack **a, t_stack **b, t_stack *node)
{
	while ((*a)->nb != node->nb || (*b)->nb != target_in_b(b, node)->nb)
		rrr(a, b);
	while ((*a)->nb != node->nb)
		rra(a);
	while ((*b)->nb != target_in_b(b, node)->nb)
		rrb(b);
	pb(a, b);
}

void	execute_operations_ra_rrb(t_stack **a, t_stack **b, t_stack *node)
{
	while ((*a)->nb != node->nb)
		ra(a);
	while ((*b)->nb != target_in_b(b, node)->nb)
		rrb(b);
	pb(a, b);
}

void	execute_operations_rra_rb(t_stack **a, t_stack **b, t_stack *node)
{
	while ((*a)->nb != node->nb)
		rra(a);
	while ((*b)->nb != target_in_b(b, node)->nb)
		rb(b);
	pb(a, b);
}
