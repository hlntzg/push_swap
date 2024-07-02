/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:53:48 by hutzig            #+#    #+#             */
/*   Updated: 2024/07/02 16:06:12 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sorting(t_stack **a, t_stack **b)
{
	if (stack_sorting_check(a))
	{	
		ft_free_stack(a);
		ft_free_stack(b);
		exit(EXIT_SUCCESS);
	}
	printf("sort the thing now ! pls");
}
