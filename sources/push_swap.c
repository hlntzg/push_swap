/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:09:10 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/30 15:50:28 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	stack_processing(argc, argv, &a);
	if (!a || stack_checking_dup(a))
		exit_failure(&a, &b);
	if (!stack_sorting_check(&a))
		stack_sorting(&a, &b);
	exit_success(&a, &b);
}
