/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:16:42 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/20 17:51:23 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_operations_ra_rb(t_stack **a, t_stack **b, t_stack *node)
{
	printf("execute_operations_ra_rb\n");
	int	i = target_in_b(b, node)->nb;
	// usleep(5000000);
	while ((*a)->nb != node->nb && (*b)->nb != i)
	{
		printf("(*a)->nb = %d, node->nb= %d, (*a)->nb != node->nb ? %d\n", (*a)->nb, node->nb, (*a)->nb != node->nb);
		printf("(*b)->nb = %d, i = %d, (*b)->nb != i ? %d\n", (*b)->nb, i, (*b)->nb != i);
		rr(a, b);	
	}
	while ((*a)->nb != node->nb)
		ra(a);
	while ((*b)->nb != i)
		rb(b);
	pb(a, b); 
}

void	execute_operations_rra_rrb(t_stack **a, t_stack **b, t_stack *node)
{
	printf("execute_operations_rra_rrb\n");
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
	printf("execute_operations_ra_rrb\n");
	while ((*a)->nb != node->nb)
		ra(a);
	while ((*b)->nb != target_in_b(b, node)->nb)
		rrb(b);
	pb(a, b);
}

void	execute_operations_rra_rb(t_stack **a, t_stack **b, t_stack *node)
{
	printf("execute_operations_rra_rb\n");
	while ((*a)->nb != node->nb)
		rra(a);
	while ((*b)->nb != target_in_b(b, node)->nb)
		rb(b);
	pb(a, b);
}
