/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghandou <rghandou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:15:03 by rghandou          #+#    #+#             */
/*   Updated: 2025/10/22 09:43:20 by rghandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	create_stack(void)
{
	return (NULL);
}

int	is_empty(t_stack *p)
{
	return (p == NULL);
}

int	push(t_stack *s, int data)
{
	t_stack	new_node;

	new_node = (t_stack)malloc(sizeof(struct s_node));
	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->next = *s;
	*s = new_node;
	return (1);
}

int	pop(t_stack *s)
{
	t_stack	tmp;

	if (!s || !(*s))
		return (0);
	tmp = *s;
	*s = (*s)->next;
	free(tmp);
	return (1);
}

int	count_stack(t_stack *s)
{
	int		count;
	t_stack	current;

	count = 0;
	current = *s;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
