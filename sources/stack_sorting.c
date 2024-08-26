/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:53:48 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/26 14:42:19 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
//	printf("\npushing_a_to_b && sorting_three::stack b:");
//	print_stack(b);
//	printf("\npushing_a_to_b && sorting_three::stack a:");
//	print_stack(a);
//	printf("\n----------------------");
	pushing_from_b_to_a(a, b);
//	printf("\npushing_b_to_a && stack a:");
//	print_stack(a);
//	printf("\npushing_b_to_a && stack b:");
//	print_stack(b);
// 	check if a is sorted and position of min in a to ra or rra (?)
	if (!stack_sorting_check(a))
	{
//		printf("\nsorting_big::final sort");
		i = ft_stack_position(a, ft_stack_min(a));
		if (i <= ft_stack_size(a) / 2)
		{
			while ((*a)->nb != ft_stack_min(a))
				ra(a);
		}
		else
		{
			while ((*a)->nb != ft_stack_min(a))
				rra(a);
		}
	}
//	printf("\npushing_b_to_a && stack a:");
//	print_stack(a);
//	printf("\npushing_b_to_a && stack b:");
//	print_stack(b);
}

void	sorting_three(t_stack **a)
{
	if ((*a)->nb == ft_stack_max(a))
		ra(a);
	else if ((*a)->next->nb == ft_stack_max(a))
		rra(a);
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
}

void	stack_sorting(t_stack **a, t_stack **b)
{	
	if (ft_stack_size(a) == 2)
		sa(a);
	else if (ft_stack_size(a) == 3)
		sorting_three(a);
	else
		sorting_big(a, b);
}
