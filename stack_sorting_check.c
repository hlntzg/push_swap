/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:56:01 by hutzig            #+#    #+#             */
/*   Updated: 2024/07/02 15:02:17 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//  this function checks if the stack is sorted in ascending order
bool	stack_sorting_check(t_stack **a)
{
	while ((*a)->next)
	{
		if ((*a)->nb > (*a)->next->nb)
			return (false);
		(*a) = (*a)->next;
	}
	return (true);
}
