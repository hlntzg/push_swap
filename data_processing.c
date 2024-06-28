/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:01:34 by hutzig            #+#    #+#             */
/*   Updated: 2024/06/28 16:54:36 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

char    **args_processing(int argc, char **argv)
{
    char    **args;
    int     i;

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
        if(!args_checking_syntax(args[i]))
        {
            if (argc == 2)
                ft_free_array(args)
            ft_error();
        }
        i++;
    }
    return (args);
}

void    stack_appending(t_stack **a, int nb)
{
    // create new_node and add nb
    // new_node->next = NULL
    if (a == NULL)
    {
         // a = new_node
         // set prev == NULL
    }
    else
    {
        //go to last node
        //last nod->next = new_node
        //new_node prev = last node
    }
}

t_stack *stack_processing(int argc, char **argv)
{
    t_stack     *a;
    char        **args;
    int long    nb;

    a = NULL;
    args = args_processing(argc, argv);
    while (*args[i])
    {
        nb = ft_atoi(args[i]); // need to be update to int long
        if (nb < INT_MIN || nb > INT_MAX)
            ft_error();
        stack_appending(&a, nb); // add 'nb' to t_stack;
        i++;
    }
    if (argc == 2)
        ft_free_array(args);
    return (a);
}
