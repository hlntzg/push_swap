/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:09:10 by hutzig            #+#    #+#             */
/*   Updated: 2024/06/28 14:02:21 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;

    a = NULL;
    if (argc < 2)
        return (0); // "If no parameters are specified, the program must not display anything and give the prompt back."
    else
        a = stack_processing(argc, argv);
    if (!a || stack_checking_dup(a))
    {
        ft_free_stack(&a);
        ft_error();
    }
    push_swap_function // ACTUALLY DO THE SORTNG FROM HERE //

}
