/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:53:48 by hutzig            #+#    #+#             */
/*   Updated: 2024/07/19 15:01:26 by hutzig           ###   ########.fr       */
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
}

void	sorting_big(t_stack **a, t_stack **b)
{
	(void)a;
	(void)b;
}

void	stack_sorting(t_stack **a, t_stack **b)
{	
	if (ft_stack_size(a) == 2)
		sa(a);
	if (ft_stack_size(a) == 3)
		sorting_three(a);
	if (ft_stack_size(a) == 5 || ft_stack_size(a) == 4)
		sorting_small(a, b);
	else
		sorting_big(a, b);
}
