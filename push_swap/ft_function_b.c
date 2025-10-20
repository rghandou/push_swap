/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 09:49:11 by rghandou          #+#    #+#             */
/*   Updated: 2025/09/22 09:50:02 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pb(t_stack *s, t_stack *s1)
{
	int	data;

	if (is_empty(s1) || is_empty(s))
		return (0);
	data = (*s1)->data;
	pop (s1);
	push(s, data);
	return (1);
}

int	sb(t_stack	*s)
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
