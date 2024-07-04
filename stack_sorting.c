/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:53:48 by hutzig            #+#    #+#             */
/*   Updated: 2024/07/04 15:42:38 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sorting(t_stack **a, t_stack **b)
{
	(void)b;
	if (ft_stack_size(a) == 2)
		sa(a);
	else
		printf("sorting ...\n");
}
