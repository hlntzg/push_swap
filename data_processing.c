/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:01:34 by hutzig            #+#    #+#             */
/*   Updated: 2024/07/02 16:14:25 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**args_processing(int argc, char **argv)
{
	char	**args;
	int	i;

	args = NULL;
	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			ft_error();
	}
	else
		args = argv + 1;
	while (*args[i])
	{
		if (!checking_syntax_error(args[i]))
		{
			if (argc == 2)
				ft_free_array(args);
			ft_error();
		}
		i++;
	}
	return (args);
}

// create new node, add nb to its content and set next and prev to NULL;
// if the stack is empty, set the new node as the head of the list;
// else, find the last node and append the new node at the end;
static void	stack_appending(t_stack **a, int nb)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error();
	new->nb = nb;
	new->next = NULL;
	new->prev = NULL;
	if (*a == NULL)
		*a = new;
	else
	{
		last = *a;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}

t_stack	*stack_processing(int argc, char **argv)
{
	t_stack	*a;
	char	**args;
	int	nb;
	int	i;
	
	a = NULL;
	i = 0;
	args = args_processing(argc, argv);
	while (*args[i])
	{
		if (!checking_is_integer(args[i]))
		{	
			if (argc == 2)
				ft_free_array(args);
			ft_error();
		}
		nb = ft_atoi(args[i]);
		stack_appending(&a, nb);
		i++;
	}
	if (argc == 2)
		ft_free_array(args);
	return (a);
}
