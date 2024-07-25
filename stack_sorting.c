/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:53:48 by hutzig            #+#    #+#             */
/*   Updated: 2024/07/25 17:58:16 by hutzig           ###   ########.fr       */
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

void	pushing_from_a_to_b(t_stack **a, t_stack **b)
{
	find_node_to_push(a, b);
	// execute the pushing of target_in_a to the top of target_in_b  :)
}


// NATALIES CODE ///
t_stack	*find_target(t_stack **b, int position)
{
	t_stack	*pos;
	t_stack	*best_pos;
	int	best_position;

	pos = *b;
	best_pos = NULL;
	best_position = INT_MIN;
	while (pos)
	{
		if (pos->position < position && pos->position > best_position)
		{
			best_position = pos->position;
			best_pos = pos;
		}
		pos = pos->next;
	}
	if (best_pos == NULL)
		best_pos = max_index(b);
	return (best_pos);
}

void	find_node_to_push(t_stack **a, t_stack **b)
}
	int	cost_min;
	int	cost_current;
	t_stack	*tmp;
	t_stack	*target_in_b;
	t_stack	*target_in_a;

	cost_min = INT_MIN;
	tmp = *a;
	while (tmp)
	{
		target_in_b = find_target(b, tmp->position);
		cost_current = // function to calculate the moves (a, b, tmp, target_in_b)
		if (current_cost < cost_min)
		{
			cost_min = current_cost;
			target_in_a = tmp;
		}
		tmp = tmp->next;
	}
	//return (target_in_a);
	*a = target_in_a;
}

void	sorting_big(t_stack **a, t_stack **b)
{
	int	i;

	i = 2;
	while (ft_stack_size(a) > 3 && i--)
		pb(a, b);
	if (ft_stack_size(a) > 3)
		pushing_from_a_to_b(a, b); // function to calculate and push to 'b' in right position
	if (!stack_sorting_check(a))
		sorting_three(a);
	pushing_from_b_to_a();
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
