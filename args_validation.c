/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:32:55 by hutzig            #+#    #+#             */
/*   Updated: 2024/06/20 16:40:22 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  ft_isnumber(char *str)
{

    return (1); // true
    return (0); // false

}

static int  ft_isduplicate()
{

}

void    args_checking(int argc, char **argv)
{
    char        **args;
    int         i;
    long int    nb;
        
    i = 1;
    if (argc == 2)
         args = ft_split(*argv[i], ' ');
    if (argc > 2)
        args = argv;
    while (*args[i])
    {
        nb = ft_atoi(args[i]);
        if (!ft_isnumber(args[i]))
               // Error\n;
        if (nb < INT_MIN || nb > INT_MAX)
               // Error\n;
        if (ft_isduplicate())
               // Error\n;
        i++;
    }
}
