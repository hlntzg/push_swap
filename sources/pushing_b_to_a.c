/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:58:22 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/30 15:02:29 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*target_in_a(t_stack **a, t_stack *node_b)
{
	t_stack *node_a;
	t_stack	*tmp;

	tmp = *a;
	node_a = NULL;
	if (node_b->nb < tmp->nb && node_b->nb > ft_stack_last(&tmp)->nb)
		return (tmp);
	if (node_b->nb > ft_stack_max(a) || node_b->nb < ft_stack_min(a))
	{
		while (tmp->nb != ft_stack_min(a))
			tmp = tmp->next;
		node_a = tmp;
		//return (tmp);
	}
	while (tmp->next)
	{
		if (node_b->nb > tmp->nb && node_b->nb < tmp->next->nb)
		//	return (tmp->next);
			node_a = tmp->next;
		tmp = tmp->next;
	}
	return (node_a);
}
/*	while (tmp)
	{
		if ((b_node->nb > ft_stack_max(a) || b_node->nb < ft_stack_min(a)) && tmp->nb == ft_stack_min(a))
		{
			a_node = tmp;
			break ;
		}
		//if (b_node->nb < tmp->nb && (!a_node || a_node->nb > tmp->nb))
		//	 	a_node = tmp;
		if (tmp->next)
		{
			if (b_node->nb > tmp->nb && b_node->nb < (tmp->next->nb))
			{
				a_node = tmp->next;
				break;
			}
		}
		tmp = tmp->next;
	}
	return (a_node);
*/

/*
int	calculate_operations_to_a(t_stack **a, t_stack **b, t_stack *node)
{
	int	position_a;
	int	position_b;

	position_a = ft_stack_position(a, (target_in_a(a, node))->nb);
	position_b = ft_stack_position(b, node->nb);
	if (position_a <= (ft_stack_size(a) / 2) && position_b <= (ft_stack_size(b) / 2))
	{
		if (position_a > position_b)
			return (position_a);
		else
		{
			return (position_b);
		}
			
	}
	else if (position_a > (ft_stack_size(a) / 2) && position_b > (ft_stack_size(b) / 2))
	{
		if ((ft_stack_size(a) - position_a) > (ft_stack_size(b) - position_b))
			return (ft_stack_size(a) - position_a);
		else
			return (ft_stack_size(b) - position_b);
	}
	else if (position_a <= (ft_stack_size(a) / 2) && position_b > (ft_stack_size(b) / 2))
	{
		return (position_a + (ft_stack_size(b) - position_b));
	}
	else if (position_a > (ft_stack_size(a) / 2) && position_b <= (ft_stack_size(b) / 2))
	{
		return ((ft_stack_size(a) - position_a) + position_b);
	}	
	else
		return (-1);
//	return ((ft_stack_size(a) - position_a) + position_b);
}
*/
/*
t_stack	*find_node_to_push_to_a(t_stack **a, t_stack **b)
{
	int	max_b;
	t_stack *tmp;

	tmp = *b;
	max_b = ft_stack_max(b);
	while (tmp->nb != max_b)
		tmp = tmp->next;
	return (tmp);
}
*/

int	calculate_operations_to_a(t_stack **a, t_stack **b, t_stack *node, t_stack *target) 
{
	int	moves;
	int	rev_moves;
	
	target = target_in_a(a, node);
	node->info.rotate = ft_stack_position(b, node->nb);
	target->info.rotate = ft_stack_position(a, target->nb);
	node->info.reverse = ft_stack_size(b) - ft_stack_position(b, node->nb);
	target->info.reverse = ft_stack_size(a) - ft_stack_position(a, target->nb);
	
	moves = ft_max(node->info.rotate, target->info.rotate);
	rev_moves = ft_max(node->info.reverse, target->info.reverse);
	if (moves > node->info.rotate + target->info.reverse)
		moves = node->info.rotate + target->info.reverse;
	if (moves > node->info.reverse + target->info.rotate)
		moves = node->info.reverse + target->info.rotate;
	if (moves > rev_moves)
		moves = rev_moves;
	return (moves);
}

t_stack	*find_node_to_push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stack	*target;
	t_stack	*tmp;
	int		min_moves;
	int		moves;

	node = NULL;
	tmp = *b;
//	tmp->info.moves = INT_MAX;
	moves = INT_MAX;
	while (tmp)
	{
		target = target_in_a(a, tmp);
		min_moves = calculate_operations_to_a(a, b, tmp, target);
		if (moves > min_moves)
		//if (operations > calculate_operations_to_a(a, b, tmp))
		{
			tmp->info.moves = min_moves;
			moves = min_moves;	
			node = tmp;
		}
		tmp = tmp->next;
	}
	return (node);
}

void	pushing_from_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*node_b;
	t_stack	*target;

	while (*b)
	{
		node_b = find_node_to_push_to_a(a, b);
		target = target_in_a(a, node_b);
		if (node_b->info.moves == node_b->info.rotate || node_b->info.moves == target->info.rotate)
			execute_rr_ra_rb(a, b, target, node_b);
		else if (node_b->info.moves == node_b->info.reverse || node_b->info.moves == target->info.reverse)
			execute_rrr_rra_rrb(a, b, target, node_b);
		else
		{
			execute_ra_or_rra(a, target); //RA or RRA
			execute_rb_or_rrb(b, node_b); //RB or RRB
		}
		pa(b, a);
	}	
}
/*
void	pushing_from_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*node_b;
	t_stack	*target;
	int		position_a;
	int		position_b;

	while (*b)
	{
		node_b = find_node_to_push_to_a(a, b);
		target = target_in_a(a, node_b);
		position_a = ft_stack_position(a, target->nb);
		position_b = ft_stack_position(a, node_b->nb);
		if (position_a <= (ft_stack_size(a) / 2) && position_b <= (ft_stack_size(b) / 2))
			execute_ra_rb(b, a, node_b, 1);
		else if (position_a > (ft_stack_size(a) / 2) && position_b > (ft_stack_size(b) / 2))
			execute_rra_rrb(b, a, node_b, 1);
		else if (position_a <= (ft_stack_size(a) / 2) && position_b > (ft_stack_size(b) / 2))
			execute_ra_rrb(b, a, node_b, 1);
		else if (position_a > (ft_stack_size(a) / 2) && position_b <= (ft_stack_size(b) / 2))
			execute_rra_rb(b, a, node_b, 1);
		pa(b, a);
	}

}*/
