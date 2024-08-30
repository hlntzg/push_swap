/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:55:06 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/30 15:01:30 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*target_in_b(t_stack **b, t_stack *node_a)
{
	t_stack	*node_b;
	t_stack *tmp;
	
	tmp = *b;
	node_b = NULL;
	if (node_a->nb > tmp->nb && node_a->nb < ft_stack_last(&tmp)->nb)
		return (tmp);
	else if (node_a->nb > ft_stack_max(b) || node_a->nb < ft_stack_min(b))
	{
		while (tmp->nb != ft_stack_max(b))
			tmp = tmp->next;
		node_b = tmp; //return (tmp);
	}
	while (tmp->next)
	{
		 if (node_a->nb < tmp->nb && node_a->nb > tmp->next->nb)
			node_b = tmp->next;
		//	return (tmp->next);
		tmp = tmp->next; 
	}
	return (node_b);
}
	/*while (tmp)
	{
		if ((a_node->nb > ft_stack_max(b) || a_node->nb < ft_stack_min(b)) && tmp->nb == ft_stack_max(b))
		{
			b_node = tmp;
			break ;
		}
		//if (a_node->nb > tmp->nb && (!b_node || b_node->nb < tmp->nb))
		//	 	b_node = tmp;
		if (tmp->next)
		{
			if (a_node->nb < tmp->nb && a_node->nb > (tmp->next->nb))
			{
				b_node = tmp->next;
				break;
			}
		}
		tmp = tmp->next;
	}
	return (b_node);*/

int	ft_max(int a, int b) // add to libft ?
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	calculate_operations_to_b(t_stack **a, t_stack **b, t_stack *node, t_stack *target) 
{
	int	moves;
	int	rev_moves;
	
	target = target_in_b(b, node);
	node->info.rotate = ft_stack_position(a, node->nb);
	target->info.rotate = ft_stack_position(b, target->nb);
	node->info.reverse = ft_stack_size(a) - ft_stack_position(a, node->nb);
	target->info.reverse = ft_stack_size(b) - ft_stack_position(b, target->nb);
	
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
/*
int	calculate_operations_to_b(t_stack **a, t_stack **b, t_stack *node)
{
	int	a;
	int	b;
	int	a_size;
	int	b_size;

	a = ft_stack_position(a, node->nb);
	b = ft_stack_position(b, (target_in_b(b, node))->nb);
	a_size = ft_stack_size(a);
	b_size = ft_stack_size(b);
	

	if (a <= a_size / 2 && b <= b_size / 2)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else if (a > a_size / 2 && b > b_size / 2)
	{
		if (a_size - a > b_size - b)
			return (a_size - a);
		else
			return (b_size - b);
	}
	else if (a <= a_size / 2 && b > b_size / 2)
		return (a + (b_size - b));
	else if (a > a_size / 2 && b <= b_size / 2)
		return ((a_size - a) + b);
	else
		return (-1);
}*/

t_stack	*find_node_to_push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stack	*target;
	t_stack	*tmp;
	int		min_moves;
	int		moves;
	
	node = NULL;
	tmp = *a;
//	tmp->info.moves = INT_MAX;
	moves = INT_MAX;
	//tmp->info.moves = 0;
	while (tmp)
	{	
		target = target_in_b(b, tmp);
		min_moves = calculate_operations_to_b(a, b, tmp, target);
		if (moves > min_moves)
		{
			tmp->info.moves = min_moves;
			moves = min_moves;
			node = tmp;
		}
		tmp = tmp->next;
	}
	return (node);
}

void	pushing_from_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*node_a;
	t_stack	*target;

	while (ft_stack_size(a) > 3 && !stack_sorting_check(a))
	{
		node_a = find_node_to_push_to_b(a, b);
		target = target_in_b(b, node_a);
		if (node_a->info.moves == node_a->info.rotate || node_a->info.moves == target->info.rotate)
	//	{
	//		printf("\npushing_from_a_to_b::if");
		 	execute_rr_ra_rb(a, b, node_a, target);
	//	}
		else if (node_a->info.moves == node_a->info.reverse || node_a->info.moves == target->info.reverse)
	//	{
	//		printf("\npushing_from_a_to_b::else if");
			execute_rrr_rra_rrb(a, b, node_a, target);
	//	}
		else
		{
	//		printf("\npushing_from_a_to_b::else");
			execute_ra_or_rra(a, node_a);
			execute_rb_or_rrb(b, target);
		}
		pb(a, b);

	}
}
/*
void	pushing_from_a_to_b(t_stack **a, t_stack **b)

	t_stack	*node_a;
	t_stack	*target;
	int		position_a;
	int		position_b;

		node_a = find_node_to_push_to_b(a, b);
		target = target_in_b(b, node_a);
		position_a = ft_stack_position(a, node_a->nb);
		position_b = ft_stack_position(b, target->nb);
		if (position_a <= (ft_stack_size(a) / 2) && position_b <= (ft_stack_size(b) / 2))
			execute_ra_rb(a, b, node_a, 2); 
		else if (position_a > (ft_stack_size(a) / 2) && position_b > (ft_stack_size(b) / 2))
			execute_rra_rrb(a, b, node_a, 2);
		else if (position_a <= (ft_stack_size(a) / 2) && position_b > (ft_stack_size(b) / 2))
			execute_ra_rrb(a, b, node_a, 2);
		else if (position_a > (ft_stack_size(a) / 2) && position_b <= (ft_stack_size(b) / 2))
			execute_rra_rb(a, b, node_a, 2);
		pb(a, b);*/
/*
void	individual_best(t_stack **a, t_stack **b, t_stack)
{
	if (node->info.rotate < node->info.reverse)
		RA
	else
		RRA
	if (target->info.rotate < target->info.reverse)
		RB
	else
		RRB
}*/
