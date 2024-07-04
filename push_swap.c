/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:09:10 by hutzig            #+#    #+#             */
/*   Updated: 2024/07/04 14:34:09 by hutzig           ###   ########.fr       */
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
	else
		a = stack_processing(argc, argv, a);
	if (!a || stack_checking_dup(a))
		exit_failure(&a, &b);
//	{
//		ft_free_stack(&a);
//		ft_error();
//	}
	stack_sorting(&a, &b);
	if (stack_sorting_check(&a))
		exit_success(&a, &b);
//	{
//		ft_free_stack(&a);
//		ft_free_stack(&b);
//	}
	return (0);
}
