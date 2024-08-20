/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:55:06 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/20 17:47:59 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*target_in_b(t_stack **b, t_stack *a_node)
{
	t_stack	*b_node;
	t_stack *tmp;
	
	tmp = *b;
	b_node = NULL;
	if (a_node->nb < tmp->nb && a_node->nb > ft_stack_last(&tmp)->nb)
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
	else if (position_a > ft_stack_size(a) / 2 && position_b < ft_stack_size(b) / 2)
		return ((ft_stack_size(a) - position_a) + position_b);
	return (0);
}

t_stack	*find_node_to_push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stack	*tmp;
	int		operations;

	tmp = *a;
//	node = tmp;
	operations = INT_MAX; //calculate_operations_to_b(a, b, tmp);
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
	t_stack	*node;
	int		position_a;
	int		position_b;

	while (ft_stack_size(a) > 3 && !stack_sorting_check(a))
	{
		node = find_node_to_push_to_b(a, b);
		position_a = ft_stack_position(a, node->nb);
		position_b = ft_stack_position(b, (target_in_b(b, node))->nb);
		if (position_a <= ft_stack_size(a) / 2 && position_b <= ft_stack_size(b) / 2)
			execute_operations_ra_rb(a, b, node); 
		else if (position_a >= ft_stack_size(a) / 2 && position_b >= ft_stack_size(b) / 2)
			execute_operations_rra_rrb(a, b, node);
		else if (position_a < ft_stack_size(a) / 2 && position_b > ft_stack_size(b) / 2)
			execute_operations_ra_rrb(a, b, node);
		else if (position_a > ft_stack_size(a) / 2 && position_b < ft_stack_size(b) / 2)
			execute_operations_rra_rb(a, b, node);
	}
}
