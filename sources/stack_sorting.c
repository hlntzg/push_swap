/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:53:48 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/19 17:24:49 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_three(t_stack **a)
{
	if ((*a)->nb == ft_stack_min(a))
	{
		rra(a);
		sa(a);
	}
	else if ((*a)->nb == ft_stack_max(a))
	{
		ra(a);
		if (!stack_sorting_check(a))
			sa(a);
	}
	else
	{
		if ((ft_stack_last(a))->nb == ft_stack_min(a))
			rra(a);
		else if ((ft_stack_last(a))->nb == ft_stack_max(a))
			sa(a);
	}
}
/*
void	sorting_three(t_stack **a)
{
	if ((*a)->nb == ft_stack_max(a);
		ra(a);
	else if ((*a)->next == ft_stack_max(a));
		rra(a);
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
}
*/
/* MAYBE NOT NECESSARY FUNCTION
void	sorting_small(t_stack **a, t_stack **b)
{
	int	i;

	while (ft_stack_size(a) > 3)
	{
		i = ft_stack_position(a, ft_stack_min(a));
		if (i <= (ft_stack_size(a) / 2))
		{
			while (i--)
				ra(a);
			pb(a, b);
		}
		else
		{
			while (i++ < ft_stack_size(a))
				rra(a);
			pb(a, b);
		}
	}
	if (!stack_sorting_check(a))
		sorting_three(a);
	while (*b)
		pa(b, a);
}*/

t_stack	*target_in_b(t_stack **a, t_stack **b, t_stack *a_node)
{
	t_stack	*b_node;
	t_stack *tmp;
	
	tmp = *b;
	b_node = NULL;
	if (a_node->nb < tmp->nb && a_node->nb > ft_stack_last(tmp)->nb)
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
/*
	if (a_node->nb > ft_stack_max(b) || a_node->nb < ft_stack_min(b))
	{
		while (tmp)
		{
			if (tmp->nb == ft_stack_max(b))
			{
				b_node = tmp; // node in b which is the node that contains ft_stack_max(b)
				break ;
			}
			tmp = tmp->next;
		}
	}
	else if (a_node->nb < tmp->nb && a_node->nb > ft_stack_last(tmp)->nb)
		b_node = tmp;
	else
	{
		while (tmp)
		{
			if (a_node->nb > tmp->nb && (!b_node || b_node->nb < tmp->nb))
				b_node = tmp;
			tmp = tmp->next;
		}
	}
	return (b_node);
}*/

int	calculate_operations_to_b(t_stack **a, t_stack **b, t_stack *node)
{
	int	position_a;
	int	position_b;

	position_a = ft_stack_position(a, node->nb);
	position_b = ft_stack_position(b, (target_in_b(a, b, node))->nb);
	if (position_a < ft_stack_size(a) / 2 && position_b < ft_stack_size(b) / 2)
	{
		if (position_a > position_b)
			return (position_a);
		else
			return (position_b);
	}
	else if (position_a > ft_stack_size(a) / 2 && position_b > ft_stack_size(b) / 2)
	{
		if ((ft_stack_size(a) - position_a) > (ft_stack_size(b) - position_b))
			return (ft_stack_size(a) - positon_a);
		else
			return (ft_stack_size(b) - position_b);
	}
	else if (position_a < ft_stack_size(a) / 2 && position_b > ft_stack_size(b) / 2)
		return (position_a + (ft_stack_size(b) - position_b));
	else if (position_a > ft_stack_size(a) / 2 && position_b < ft_stack_size(b) / 2)
		return ((ft_stack_size(a) - position_a) + position_b);
}

t_stack	*find_node_to_push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stack	*tmp;
	int		operations;

	tmp = *a;
	node = tmp;
	operations = calculate_operations_to_b(a, b, node);
	while (tmp)
	{
		if (operations < calculate_operations_to_b(a, b, node))
		{
			operations = calculate_operations_to_b(a, b, node);
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
		position_b = ft_stack_position(b, (target_in_b(a, b, node))->nb);
		if (position_a < ft_stack_size(a) / 2 && position_b < ft_stack_size(b) / 2)
			execute_operations_ra_rb(a, b, node); 
		else if (position_a > ft_stack_size(a) / 2 && position_b > ft_stack_size(b) / 2)
			execute_operations_rra_rrb(a, b, node);
		else if (position_a < ft_stack_size(a) / 2 && position_b > ft_stack_size(b) / 2)
			execute_operations_ra_rrb(a, b, node);
		else if (position_a > ft_stack_size(a) / 2 && position_b < ft_stack_size(b) / 2)
			execute_operations_rra_rb(a, b, node);
	}
}

t_stack *target_in_a(t_stack **a, t_stack **b)
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

void	sorting_big(t_stack **a, t_stack **b)
{
	int	i;

	i = 2;
	while (ft_stack_size(a) > 3 && i--)
		pb(a, b);
	if (ft_stack_size(a) > 3)
		pushing_from_a_to_b(a, b);
	if (!stack_sorting_check(a))
		sorting_three(a);
	pushing_from_b_to_a(a, b);
	// check if a is sorted and position of min in a to ra or rra (?)
}

void	stack_sorting(t_stack **a, t_stack **b)
{	
	if (ft_stack_size(a) == 2)
		sa(a);
	if (ft_stack_size(a) == 3)
		sorting_three(a);
//	if (ft_stack_size(a) == 5 || ft_stack_size(a) == 4)
//		sorting_small(a, b);
	else
		sorting_big(a, b);
}
