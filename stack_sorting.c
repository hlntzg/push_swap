/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:53:48 by hutzig            #+#    #+#             */
/*   Updated: 2024/07/04 12:37:21 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sorting(t_stack **a, t_stack **b)
{
	if (stack_sorting_check(a))
		exit_success(a, b);
//	{	
//		ft_free_stack(a);
//		ft_free_stack(b);
//		exit(EXIT_SUCCESS);
//	}
	t_stack *temp;
	temp = *a;

    if (ft_stack_size(&temp) == 2)
        sa(a);
    else
        printf("sorting ...\n");
}
