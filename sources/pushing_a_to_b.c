/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:55:06 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/29 17:23:02 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*target_in_b(t_stack **b, t_stack *a_node)
{
	t_stack	*b_node;
	t_stack *tmp;
	
	tmp = *b;
	b_node = NULL;
	if (a_node->nb > tmp->nb && a_node->nb < ft_stack_last(&tmp)->nb)
		return (tmp);
	if (a_node->nb > ft_stack_max(b) || a_node->nb < ft_stack_min(b))
	{
		while (tmp->nb != ft_stack_max(b))
			tmp = tmp->next;
		return (tmp);
	}
	while (tmp->next)
	{
		if (a_node->nb < tmp->nb && a_node->nb > tmp->next->nb)
			return (tmp->next);
		tmp = tmp->next; 
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
}

// TO DO

int	get_rotate_moves(t_stack **stack, t_stack *node)
{
	ft_stack_position // ??
	
}

int	get_reverse_moves(t_stack **stack, t_stack *node)
{
	ft_stack_size - ft_stack_position // ??


}

ft_max() // add to libft ?


int	calculate_operations_to_b(t_stack **a, t_stack **b, t_stack *node, t_stack *target) //could i have dir and get target here to use same function in both ways
{
	int	moves;
	int	rev_move;

	a->info.rotate = get_rotate_moves(a, node);
	b->info.rotate = get_rotate_moves(b, target);
	a->info.reverse = get_reverse_moves(a, node);
	b->info.reverse = get_reverse_moves(b, target);
	moves = ft_max(a->info.rotate, b->info.rotate);
	rev_moves = ft_max(a->info.reverse, b->info.reverse);
	if (moves > rev_moves)
		moves = rev_moves;
	if (moves > a->info.rotate + b->info.reverse)
		moves = a->info.rotate + b->info.reverse;
	if (moves > a->info.reverse + b->info.rotate)
		moves = a->info.rotate + b->info.reverse;
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
	int		min_operations;
	int		operations;
	
	node = NULL;
	tmp = *a;
	min_operations = INT_MAX;
	while (tmp)
	{	
		target = target_in_b(a, b);		
		operations = calculate_operations_to_b(a, b, tmp, target);
		if (operations > min_operations)
		{
			operations = min_operations;
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
	int		position_a;
	int		position_b;

	while (ft_stack_size(a) > 3 && !stack_sorting_check(a))
	{
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
		pb(a, b);
	}
}
