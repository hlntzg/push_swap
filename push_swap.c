/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:09:10 by hutzig            #+#    #+#             */
/*   Updated: 2024/07/04 15:28:42 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	print_stack(t_stack **a)
{
	int	i = 0;

	while (*a)
	{
		printf("[%d] %d\n", i, (*a)->nb);
		(*a) = (*a)->next;
		i++;
	}		
}
*/
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = stack_processing(argc, argv, a);
	if (!a || stack_checking_dup(a))
		exit_failure(&a, &b);
	if (!stack_sorting_check(&a))
		stack_sorting(&a, &b);
	exit_success(&a, &b);
}
