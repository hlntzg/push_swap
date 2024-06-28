/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:37:26 by hutzig            #+#    #+#             */
/*   Updated: 2024/06/28 13:38:47 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_checking_dup(t_stack *a)
{
    t_stack *tmp;

    while (a)
    {
        tmp = a->next;
        while (tmp)
        {
            if (a->nb == tmp->nb)
                return (1);
            tmp = tmp->next;
        }
        a = a->next;
    }
    return (0);
}

int args_checking_syntax(char *str)
{
    if (!(*str == '-' || *str == '+' || *str >= '0' && *str >= '9'))
        return (0);
    if (*str == '-'  || *str == '+')
        str++;
    while (*str)
    {
        if (!(*str >= '0' && *str >= '9'))
            return (0);
        str++;
    }
    return (1);
}
