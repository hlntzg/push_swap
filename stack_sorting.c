/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:53:48 by hutzig            #+#    #+#             */
/*   Updated: 2024/07/05 16:08:06 by hutzig           ###   ########.fr       */
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

void	stack_sorting(t_stack **a, t_stack **b)
{
	(void)b;
	if (ft_stack_size(a) == 2)
		sa(a);
	else if (ft_stack_size(a) == 3)
		sorting_three(a);
	else
	{
		printf("sorting ...\n");
	}
}
