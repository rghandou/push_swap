/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 09:49:11 by rghandou          #+#    #+#             */
/*   Updated: 2025/10/22 10:14:29 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pb(t_stack *b, t_stack *a)
{
	int	data;

	if (is_empty(a))
		return (0);
	data = (*a)->data;
	pop (a);
	push(b, data);
	write(1, "pb\n", 3);
	return (1);
}

int	sb(t_stack	*s)
{
	int	tmp;

	if (!s || !(*s) || !(*s)->next)
		return (0);
	tmp = (*s)->data;
	(*s)->data = (*s)->next->data;
	(*s)->next->data = tmp;
	write(1, "sb\n", 3);
	return (1);
}

int	rb(t_stack	*s)
{
	t_stack	first;
	t_stack	current;

	if (!s || !(*s) || !(*s)->next)
		return (0);
	first = *s;
	*s = (*s)->next;
	first->next = NULL;
	current = *s;
	while (current->next)
		current = current->next;
	current->next = first;
	write(1, "rb\n", 3);
	return (1);
}

int	rrb(t_stack	*s)
{
	t_stack	last;
	t_stack	current;

	if (!s || !(*s) || !(*s)->next)
		return (0);
	while (current->next)
		current = current->next;
	current->next = last;
	current->next = NULL;
	last->next = *s;
	*s = last;
	write(1, "rrb\n", 4);
	return (1);
}
