/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 09:50:26 by rghandou          #+#    #+#             */
/*   Updated: 2025/10/22 10:27:56 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_stack *s)
{
	while (*s)
		pop(s);
}

int	is_sorted(t_stack s)
{
	while (s && s->next)
	{
		if (s->data > s->next->data)
			return (0);
		s = s->next;
	}
	return (1);
}

int	ss(t_stack	*a, t_stack *b)
{
	int	result_a;
	int	result_b;
	int	tmp;

	result_a = 0;
	result_b = 0;
	if (a && *a && (*a)->next)
	{
		tmp = (*a)->data;
		(*a)->data = (*a)->next->data;
		(*a)->next->data = tmp;
		result_a = 1;
	}
	if (b && *b && (*b)->next)
	{
		tmp = (*b)->data;
		(*b)->data = (*b)->next->data;
		(*b)->next->data = tmp;
		result_b = 1;
	}
	if (result_b || result_a)
		write(1, "ss\n", 3);
	return (result_a || result_b);
}

int	rr(t_stack *a, t_stack *b)
{
	int	result_a;
	int	result_b;

	result_a = 0;
	result_b = 0;
	if (a && *a && (*a)->next)
	{
		ra(a);
		result_a = 1;
	}
	if (b && *b && (*b)->next)
	{
		rb(b);
		result_b = 1;
	}
	if (result_b || result_a)
		write(1, "rr\n", 3);
	return (result_a || result_b);
}

int	rrr(t_stack	*a, t_stack *b)
{
	int	result_a;
	int	result_b;

	result_a = 0;
	result_b = 0;
	if (a && *a && (*a)->next)
	{
		rra(a);
		result_a = 1;
	}
	if (b && *b && (*b)->next)
	{
		rrb(b);
		result_b = 1;
	}
	if (result_b || result_a)
		write(1, "rrr\n", 4);
	return (result_a || result_b);
}
