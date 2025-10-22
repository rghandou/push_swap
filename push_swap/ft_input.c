/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:20:57 by rghandou          #+#    #+#             */
/*   Updated: 2025/10/22 10:23:47 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack s)
{
	while (s)
	{
		ft_putnbr(s->data);
		s = s->next;
		write(1, "\n", 1);
	}
}

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    int *array;
    int length;
    int i;
    int j;

    if (argc < 2)
        return (0);
    stack_a = create_stack();
    stack_b = create_stack();
    i = 0;
    while (++i < argc)
    {
        array = creation_array(argv[i], &length);
        if (!array)
        {
            clear_stack(&stack_a);
            return (1);
        }
        j = length;
        while (--j >= 0)
        {
            if (!push(&stack_a, array[j]))
            {
                free(array);
                clear_stack(&stack_a);
                write(2, "Error\n", 6);
                return (1);
            }
        }
        free(array);
    }
    if (is_sorted(stack_a))
    {
        clear_stack(&stack_a);
        return (0);
    }

    if (count_stack(&stack_a) <= 5)
        sort_small(&stack_a, &stack_b);
    else
    {
        write(2, "Error: Large input sorting not implemented\n", 42);
        clear_stack(&stack_a);
        clear_stack(&stack_b);
        return (1);
    }

    clear_stack(&stack_a);
    clear_stack(&stack_b);
    return (0);
}