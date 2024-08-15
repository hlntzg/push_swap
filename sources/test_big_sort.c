void	pushing_from_a_to_b(t_stack **a, t_stack **b)
{
	find_node_to_push(a, b);
	// execute the pushing of target_in_a to the top of target_in_b  :)
}
/*

// NATALIES CODE ///
t_stack	*find_target(t_stack **b, int position)
{
	t_stack	*pos;
	t_stack	*best_pos;
	int		best_position;

	pos = *b;
	best_pos = NULL;
	best_position = INT_MIN;
	while (pos)
	{
		if (pos->position < position && pos->position > best_position)
		{
			best_position = pos->position;
			best_pos = pos;
		}
		pos = pos->next;
	}
	if (best_pos == NULL)
		best_pos = max_index(b);
	return (best_pos);
}

void	find_node_to_push(t_stack **a, t_stack **b)
}
	int		cost_min;
	int		cost_current;
	t_stack	*tmp;
	t_stack	*target_in_b;
	t_stack	*target_in_a;

	cost_min = INT_MAX;
	tmp = *a;
	while (tmp)
	{
		target_in_b = find_target(b, tmp->position);
		cost_current = // function to calculate the moves (a, b, tmp, target_in_b)
		if (current_cost < cost_min)
		{
			cost_min = current_cost;
			target_in_a = tmp;
		}
		tmp = tmp->next;
	}
	//return (target_in_a);
	*a = target_in_a;
}
*/

