/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:09:10 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/23 15:25:17 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack **a)
{
	t_stack	*tmp = *a;
	while (tmp)
	{
		printf("\n%d", tmp->nb);
		tmp = tmp->next;
	}		
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	stack_processing(argc, argv, &a);
	if (!a || stack_checking_dup(a))
		exit_failure(&a, &b);
	if (!stack_sorting_check(&a))
		stack_sorting(&a, &b);
	exit_success(&a, &b);
/*	printf("\nBefore:\n");
	print_stack(&a);
	printf("\n\naction:\n");
	pb(&a, &b);
	printf("\n\naction:\n");
	pb(&a, &b);
	printf("\n\naction:\n");
	pb(&a, &b);
	printf("\nAfter a:\n");
	print_stack(&a);
	printf("\nAfter b:\n");
	print_stack(&b);
	printf("\n\naction:\n");
	rr(&a, &b);
	printf("\n\nAfter a:\n");
	print_stack(&a);
	printf("\n\nAfter b:\n");
	print_stack(&b);
	printf("\n\naction:\n");
	ra(&a);
	printf("\nAfter a:\n");
	print_stack(&a);
	printf("\nAfter b:\n");
	print_stack(&b);*/
}

/*
int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	stack_processing(argc, argv, &a);
	if (!a || stack_checking_dup(a))
		exit_failure(&a, &b);
	printf("\nBefore:\n");
	print_stack(&a);
	//rotate(&a);
	ra(&a);
	printf("\nAfter:\n");
	print_stack(&a);
}*/
