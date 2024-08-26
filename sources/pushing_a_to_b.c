/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:55:06 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/26 17:14:19 by hutzig           ###   ########.fr       */
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
	while (tmp)
	{
		if ((a_node->nb > ft_stack_max(b) || a_node->nb < ft_stack_min(b)) && tmp->nb == ft_stack_max(b))
		{
			b_node = tmp;
			break ;
		}
		if (a_node->nb > tmp->nb && (!b_node || b_node->nb < tmp->nb))
			b_node = tmp;
		tmp = tmp->next;
	}
	return (b_node);
}

int	calculate_operations_to_b(t_stack **a, t_stack **b, t_stack *node)
{
	int	position_a;
	int	position_b;

	position_a = ft_stack_position(a, node->nb);
	position_b = ft_stack_position(b, (target_in_b(b, node))->nb);
	if (position_a <= ft_stack_size(a) / 2 && position_b <= ft_stack_size(b) / 2)
	{
		if (position_a > position_b)
			return (position_a);
		else
			return (position_b);
	}
	else if (position_a >= ft_stack_size(a) / 2 && position_b >= ft_stack_size(b) / 2)
	{
		if ((ft_stack_size(a) - position_a) > (ft_stack_size(b) - position_b))
			return (ft_stack_size(a) - position_a);
		else
			return (ft_stack_size(b) - position_b);
	}
	else if (position_a < ft_stack_size(a) / 2 && position_b > ft_stack_size(b) / 2)
		return (position_a + (ft_stack_size(b) - position_b));
//	else if (position_a > ft_stack_size(a) / 2 && position_b < ft_stack_size(b) / 2)
//		return ((ft_stack_size(a) - position_a) + position_b);
//	else
//		return (-1);
	return ((ft_stack_size(a) - position_a) + position_b);
}

t_stack	*find_node_to_push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stack	*tmp;
	int		operations;

	tmp = *a;
	operations = INT_MAX;
	while (tmp)
	{
		if (operations > calculate_operations_to_b(a, b, tmp))
		{
			operations = calculate_operations_to_b(a, b, tmp);
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
		if (position_a <= ft_stack_size(a) / 2 && position_b <= ft_stack_size(b) / 2)
			execute_ra_rb(a, b, node_a, 2); 
		else if (position_a >= ft_stack_size(a) / 2 && position_b >= ft_stack_size(b) / 2)
			execute_rra_rrb(a, b, node_a, 2);
		else if (position_a < ft_stack_size(a) / 2 && position_b > ft_stack_size(b) / 2)
			execute_ra_rrb(a, b, node_a, 2);
		else if (position_a > ft_stack_size(a) / 2 && position_b < ft_stack_size(b) / 2)
			execute_rra_rb(a, b, node_a, 2);
		pb(a, b);
	}
}
