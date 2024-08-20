/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:01:34 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/20 15:17:33 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**args_processing(int argc, char **argv)
{
	char	**args;
	int		i;

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
	while (args[i])
	{
		if (checking_syntax_error(args[i]) || !checking_is_integer(args[i]))
		{
			if (argc == 2)
				ft_free_array(args);
			ft_error();
		}
		i++;
	}
	return (args);
}

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
		last = ft_stack_last(a);
		last->next = new;
		new->prev = last;
	}
}
/*
static	void	stack_ranking_data(t_stack **a)
{
	int		i;
	int		minimum;
	t_stack	*tmp;
	t_stack	*current;

	i = 1;
	while (i <= ft_stack_size(a))
	{
		tmp = *a;
		minimum = INT_MAX;
		current = NULL;
		while (tmp)
		{
			if (tmp->nb <= minimum && tmp->position == 0)
			{
				minimum = tmp->nb;
				current = tmp;
			}
			tmp = tmp->next;
		}
		if (current)
			current->position = i;
		i++;
	}
}
*/
void	stack_processing(int argc, char **argv, t_stack **a)
{
	char	**args;
	int		nb;
	int		i;

	i = 0;
	args = args_processing(argc, argv);
	while (args[i])
	{
		nb = ft_atoi(args[i]);
		stack_appending(a, nb);
		i++;
	}
	if (argc == 2)
		ft_free_array(args);
//	stack_ranking_data(a);
}
