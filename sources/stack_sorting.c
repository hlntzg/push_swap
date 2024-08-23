/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:53:48 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/20 11:48:16 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_big(t_stack **a, t_stack **b)
{
	int	i;

	i = 2;
	printf("sorting_big::start\n");
	while (ft_stack_size(a) > 3 && i--)
		pb(a, b);
	printf("sorting_big::first while loop done\n");
	if (ft_stack_size(a) > 3)
	{
		printf("sorting_big::pushing_from_a_to_b\n");
		pushing_from_a_to_b(a, b);
	}
	if (!stack_sorting_check(a))
		sorting_three(a);
	printf("\nstack b:");
	print_stack(b);
	printf("\nstack a:");
	print_stack(a);
//	pushing_from_b_to_a(a, b);
// 	check if a is sorted and position of min in a to ra or rra (?)
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
