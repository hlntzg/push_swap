/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:20:11 by hutzig            #+#    #+#             */
/*   Updated: 2024/07/04 15:51:32 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*t_stack *ft_stack_last(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while(tmp->next)
		tmp = tmp->next;
	return (tmp);
}
*/
int	ft_stack_size(t_stack **stack)
{
	int	i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
