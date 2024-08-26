/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:58:22 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/26 14:52:26 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *target_in_a(t_stack **a, t_stack *b_node)
{
	t_stack *a_node;
	t_stack	*tmp;

	tmp = *a;
	a_node = NULL;
	if (b_node->nb < tmp->nb && b_node->nb > ft_stack_last(&tmp)->nb)
		return (tmp);
	while (tmp)
	{
		if ((b_node->nb > ft_stack_max(a) || b_node->nb < ft_stack_min(a)) && tmp->nb == ft_stack_min(a))
		{
			a_node = tmp;
			break ;
		}
		if (b_node->nb < tmp->nb && (!a_node || a_node->nb > tmp->nb))
			a_node = tmp;
		tmp = tmp->next;
	}
	return (a_node);
}

int	calculate_operations_to_a(t_stack **a, t_stack **b, t_stack *node)
{
	int	position_a;
	int	position_b;

	position_a = ft_stack_position(a, (target_in_a(a, node))->nb);
	position_b = ft_stack_position(b, node->nb);
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
	else
		return (-1);
}

t_stack	*find_node_to_push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stack	*tmp;
	int		operations;

	tmp = *b;
	operations = INT_MAX;
	while (tmp)
	{
		if (operations > calculate_operations_to_a(a, b, tmp))
		{
			operations = calculate_operations_to_a(a, b, tmp);
			if (operations == -1)
				printf("ATTENTION IN B");
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
	int		position_a;
	int		position_b;

	while (*b)
	{
		node_b = find_node_to_push_to_a(a, b);
		target = target_in_a(a, node_b);
		position_a = ft_stack_position(a, target->nb);
		position_b = ft_stack_position(a, node_b->nb);
		if (position_a <= ft_stack_size(a) / 2 && position_b <= ft_stack_size(b) / 2)
			execute_ra_rb(b, a, node_b, 1);
		else if (position_a >= ft_stack_size(a) / 2 && position_b >= ft_stack_size(b) / 2)
			execute_rra_rrb(b, a, node_b, 1);
		else if (position_a < ft_stack_size(a) / 2 && position_b > ft_stack_size(b) / 2)
			execute_ra_rrb(b, a, node_b, 1);
		else if (position_a > ft_stack_size(a) / 2 && position_b < ft_stack_size(b) / 2)
			execute_rra_rb(b, a, node_b, 1);
		pa(b, a);
	}
}
