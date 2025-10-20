/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:51:31 by rghandou          #+#    #+#             */
/*   Updated: 2025/10/20 11:27:54 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack *a, t_stack *b)
{
	int	data;

	if (is_empty(*b))
		return (0);
	data = (*b)->data;
	pop (b);
	push(a, data);
	write(1, "pa\n", 3);
	return (1);
}

int	sa(t_stack	*s)
{
	int	data;
	int	tmp;

	if (is_empty(s))
		return (0);
	data = (*s)->data;
	pop(s);
	tmp = (*s)->data;
	(*s)->data = data;
	push(s, tmp);
	return (1);
}

int	ra(t_stack	*s)
{
	t_stack	current;
	int		*array;
	int		length;
	int		data;

	length = 4;
	current = create_stack();
	array = malloc(length * sizeof(int));
	data = (*s)->data;
	push(&current, data);
	pop(s);
	data = 0;
	while (*s && data < length)
	{
		array[data] = (*s)->data;
		*s = (*s)->next;
		data++;
	}
	while (length > 0)
	{
		push(&current, array[length - 1]);
		length--;
	}
	*s = current;
	return (1);
}

int	rra(t_stack	*s)
{
	t_stack	current;
	int		*array;
	int		length;
	int		data;

	length = 4;
	current = create_stack();
	array = malloc(length * sizeof(int));
	data = 0;
	while (*s && data <= length)
	{
		array[data] = (*s)->data;
		*s = (*s)->next;
		data++;
	}
	data = length - 1;
	while (data >= 1)
	{
		push(&current, array[data]);
		data --;
	}
	push(&current, array[0]);
	push(&current, array[length]);
	*s = current;
	return (1);
}
