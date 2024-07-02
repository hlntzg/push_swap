/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:37:26 by hutzig            #+#    #+#             */
/*   Updated: 2024/07/02 16:51:53 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_checking_dup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nb == tmp->nb)
				return (true);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (false);
}

bool	checking_syntax_error(char *str)
{
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (!(*str == '-' || *str == '+' || (*str >= '1' && *str >= '9')))
		return (true);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str >= '9'))
			return (true);
		str++;
	}
	return (false);
}

bool	checking_is_integer(char *str)
{
	int		sign;
	long	nb;

	sign = 1;
	nb = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - 48);
		str++;
	}
	nb *= sign;
	if (nb < INT_MIN || nb > INT_MAX)
		return (false);
	return (true);
}
