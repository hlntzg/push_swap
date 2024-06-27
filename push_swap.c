/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:09:10 by hutzig            #+#    #+#             */
/*   Updated: 2024/06/27 16:39:13 by hutzig           ###   ########.fr       */
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
        a = args_processing(argc, argv); // this function will: (if argc == 2) split, atoi and add data to t_stack, (argc > 2) atoi and add to t_stack;
    if (!a || dup(a))
    {
        ft_lstclear(); // void ft_lstclear(t_list **lst, void(*del)(void*));
        ft_error();
    }

}



t_stack *args_processing(int argc, char **args)
{
    t_stack     *a;
    int long    nb;

    a = NULL;
    args_checking(argc, args);
    while (*args[i])
    {
        nb = ft_atoi(args[i]); // need to be update to int long
        //check nb 
        // add 'nb' to t_stack;
        i++;
    }
    return (a);
}

// split and check syntax (atoi and add data to t_stack another function)
char    **string_processing(char *str)
{
    char    **args;
    char    **tmp;
    int     i;
    int     nb;

    if (*str)
    {
        args = ft_split(str, ' ');
        tmp = args;
        i = 0;
        while (*tmp[i])
        {
            if(!args_checking_syntax(tmp[i]))
            {
                // free **args
                // ft_error;
            }
            i++;
        }
    }
    return (args);
}

// process arguments according argc 
void    *args_checking(int argc, char **argv)
{
    char    **args;
    char    **tmp;
    int     i;

    if (argc == 2)
    {
        args = string_processing(argv[1]);
        if (!args) // not sure if this need to be ckecked, should args == NULL in string_processing?
            return / exit // ?
    }
    else
    {
        tmp = argv;
        i = 1;
        while (i < argc)
        {
            if(!args_checking_syntax(tmp[i]))
            {
                // free tmp? argv ??
                // ft_error;
            }
            i++;
        }
        args = argv;
    }
    args_processing(args);
}
