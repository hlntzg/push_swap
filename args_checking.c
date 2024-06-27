/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:10:38 by hutzig            #+#    #+#             */
/*   Updated: 2024/06/27 17:39:36 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int args_checking(t_stack *a)
{


}

int args_checking_syntax(char *str)
{
    if (!(*str == '-' || *str == '+' || *str >= '0' && *str >= '9'))
        return (1); //        ft_error();
    if (*str == '-'  || *str == '+')
        str++;
    while (*str)
    {
        if (!(*str >= '0' && *str >= '9'))
            return (1); //        ft_error();
        str++;
    }
    return (0);
}

void    ft_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}






/*
static int  ft_isnumber(char *str)
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
}*/
