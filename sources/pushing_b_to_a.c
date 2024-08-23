/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:58:22 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/23 15:49:06 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *target_in_a(t_stack **a, t_stack **b, t_stack *b_node)
{
	t_stack *a_node;
	t_stack	*tmp;

	a_node = NULL;
	tmp = *a;
	while (tmp)
	{
		if ((*b)->nb < tmp->nb && a_node > tmp->nb)
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


}

void	pushing_from_b_to_a(t_stack **a, t_stack **b)
{
	int		position_a;

	while (*b)
	{
		position_a = ft_stack_position(a, (target_in_a(a, b)->nb));
		if (position_a == 1)
			pa(b, a);
		else if (position_a > ft_stack_size(a) / 2)
			execute_operations_rra(a, b);
		else if (position_a < ft_stack_size(a) / 2) // is this necessary? will be targert on the first half?
			execute_ra(a, node);
		(*b) = (*b)->next;
	}
}
