/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:16:42 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/23 15:40:08 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_operations_ra_rb(t_stack **a, t_stack **b, t_stack *node)
{
	//usleep(5000000);
	while ((*a)->nb != node->nb && (*b)->nb != target_in_b(b, node)->nb)
//	{	
//		printf("execute_operations_ra_rb::rr\n");
		rr(a, b);
//	}
	while ((*a)->nb != node->nb)
//	{
//		printf("execute_operations_ra_rb:ra\n");
		ra(a);
//	}
	while ((*b)->nb != target_in_b(b, node)->nb)
//	{
//		printf("execute_operations_ra_rb:rb\n");
		rb(b);
//	}
	pb(a, b); 
}

void	execute_operations_rra_rrb(t_stack **a, t_stack **b, t_stack *node)
{
//	printf("execute_operations_rra_rrb\n");
	while ((*a)->nb != node->nb && (*b)->nb != target_in_b(b, node)->nb)
		rrr(a, b);
	while ((*a)->nb != node->nb)
		rra(a);
	while ((*b)->nb != target_in_b(b, node)->nb)
		rrb(b);
	pb(a, b);
}

void	execute_operations_ra_rrb(t_stack **a, t_stack **b, t_stack *node)
{
//	printf("execute_operations_ra_rrb\n");
	while ((*a)->nb != node->nb)
		ra(a);
	while ((*b)->nb != target_in_b(b, node)->nb)
		rrb(b);
	pb(a, b);
}

void	execute_operations_rra_rb(t_stack **a, t_stack **b, t_stack *node)
{
//	printf("execute_operations_rra_rb\n");
	while ((*a)->nb != node->nb)
		rra(a);
	while ((*b)->nb != target_in_b(b, node)->nb)
		rb(b);
	pb(a, b);
}
