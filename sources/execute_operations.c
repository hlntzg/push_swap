/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:16:42 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/30 11:39:30 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rr_ra_rb(t_stack **a, t_stack **b, t_stack *node_a, t_stack *node_b)
{
	//while (node->info.rotate > 0 && target->info.rotate > 0);
	
	while (*a != node_a && *b != node_b)
		rr(a, b);
	while (*a != node_a)
		ra(a);
	while (*b != node_b)
		rb(b);
}

void	execute_rrr_rra_rrb(t_stack **a, t_stack **b, t_stack *node_a, t_stack *node_b)
{
	while (*a != node_a && *b != node_b)
		rrr(a, b);
	while (*a != node_a)
		rra(a);
	while (*b != node_b)
		rrb(b);
}

void	execute_ra_or_rra(t_stack **a, t_stack *node)
{
	if (node->info.rotate < node->info.reverse)
	{
		while (*a != node)
			ra(a);
	}
	else
	{
		while (*a != node)
			rra(a);
	}
}

void	execute_rb_or_rrb(t_stack **b, t_stack *node)
{
	if (node->info.rotate < node->info.reverse)
	{
		while (*b != node)
			rb(b);
	}
	else
	{
		while (*b != node)
			rrb(b);
	}
}


/*
void	execute_operations_ra_rb(t_stack **a, t_stack **b, t_stack *node)
{
	//usleep(5000000);
	while ((*a)->nb != node->nb && (*b)->nb != target_in_b(b, node)->nb)
		rr(a, b);
	while ((*a)->nb != node->nb)
		ra(a);
	while ((*b)->nb != target_in_b(b, node)->nb)
		rb(b);
}

void	execute_operations_rra_rrb(t_stack **a, t_stack **b, t_stack *node)
{
	while ((*a)->nb != node->nb && (*b)->nb != target_in_b(b, node)->nb)
		rrr(a, b);
	while ((*a)->nb != node->nb)
		rra(a);
	while ((*b)->nb != target_in_b(b, node)->nb)
		rrb(b);
}

void	execute_operations_ra_rrb(t_stack **a, t_stack **b, t_stack *node)
{
	while ((*a)->nb != node->nb)
		ra(a);
	while ((*b)->nb != target_in_b(b, node)->nb)
		rrb(b);
}

void	execute_operations_rra_rb(t_stack **a, t_stack **b, t_stack *node)
{
	while ((*a)->nb != node->nb)
		rra(a);
	while ((*b)->nb != target_in_b(b, node)->nb)
		rb(b);
}*/
//////////////////////////////////////////////////////////////////////////////////////
/*void	execute_ra_rb(t_stack **src, t_stack **dst, t_stack *node, int direction)
{
	t_stack	*target;

	if (direction == 1)
	{
		target = target_in_a(dst, node);
		while ((*src)->nb != node->nb && (*dst)->nb != target->nb)
			rr(dst,src);
		while ((*src)->nb != node->nb)
			rb(src);
		while ((*dst)->nb != target->nb)
			ra(dst);
	}
	else // A_TO_B
	{
		target = target_in_b(dst, node);
		while ((*src)->nb != node->nb && (*dst)->nb != target->nb)
			rr(src, dst);
		while ((*src)->nb != node->nb)
			ra(src);
		while ((*dst)->nb != target->nb)
			rb(dst);
	}
}

void	execute_rra_rrb(t_stack **src, t_stack **dst, t_stack *node, int direction)
{
	t_stack	*target;

	if (direction == 1)
	{
		target = target_in_a(dst, node);
		while ((*src)->nb != node->nb && (*dst)->nb != target->nb)
			rrr(dst,src);
		while ((*src)->nb != node->nb)
			rrb(src);
		while ((*dst)->nb != target->nb)
			rra(dst);
	}
	else // A_TO_B
	{
		target = target_in_b(dst, node);
		while ((*src)->nb != node->nb && (*dst)->nb != target->nb)
			rrr(src, dst);
		while ((*src)->nb != node->nb)
			rra(src);
		while ((*dst)->nb != target->nb)
			rrb(dst);
	}
}

void	execute_ra_rrb(t_stack **src, t_stack **dst, t_stack *node, int direction)
{
	t_stack	*target;

	if (direction == 1)
	{
		target = target_in_a(dst, node);		
		while ((*dst)->nb != target->nb)
			ra(dst);	
		while ((*src)->nb != node->nb)
			rrb(src);
	}
	else // A_TO_B
	{
		target = target_in_b(dst, node);
		while ((*src)->nb != node->nb)
			ra(src);
		while ((*dst)->nb != target->nb)
			rrb(dst);
	}
}

void	execute_rra_rb(t_stack **src, t_stack **dst, t_stack *node, int direction)
{
	t_stack	*target;

	if (direction == 1)
	{
		target = target_in_a(dst, node);
		while ((*dst)->nb != target->nb)
			rra(dst);	
		while ((*src)->nb != node->nb)
			rb(src);
	}
	else // A_TO_B
	{
		target = target_in_b(dst, node);
		while ((*src)->nb != node->nb)
			rra(src);
		while ((*src)->nb != node->nb)
			rb(src);
	}
}*/
