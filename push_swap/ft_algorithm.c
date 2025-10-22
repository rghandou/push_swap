/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algortim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:12:17 by rghandou          #+#    #+#             */
/*   Updated: 2025/10/22 10:24:14 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

// Find index of minimum element in stack
int find_min_index(t_stack s)
{
    int min = s->data;
    int index = 0;
    int min_index = 0;
    
    while (s)
    {
        if (s->data < min)
        {
            min = s->data;
            min_index = index;
        }
        s = s->next;
        index++;
    }
    return min_index;
}

// Move minimum element to top using ra or rra
void move_min_to_top(t_stack *a)
{
    int min_index = find_min_index(*a);
    int stack_size = count_stack(a);

    if (min_index <= stack_size / 2)
    {
        while (min_index-- > 0)
            ra(a);
    }
    else
    {
        min_index = stack_size - min_index;
        while (min_index-- > 0)
            rra(a);
    }
}

// Sort exactly 3 elements in stack a
void sort_three(t_stack *a)
{
    int first = (*a)->data;
    int second = (*a)->next->data;
    int third = (*a)->next->next->data;

    if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first > third)
        ra(a);
    else if (first < second && second > third && first < third)
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && first > third)
        rra(a);
}

// Sort stacks with 5 or fewer elements
void sort_small(t_stack *a, t_stack *b)
{
    while (count_stack(a) > 3)
    {
        move_min_to_top(a);
        pb(b, a);
    }
    sort_three(a);
    while (!is_empty(b))
        pa(a, b);
}
